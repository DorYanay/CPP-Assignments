#include "MagicalContainer.hpp"
#include <cmath>
using namespace std;
namespace ariel
{
    /*   _______  _______  _______ _________ _______  _______  _           _______  _______  __      _________ _______ _________ __       _______  _______
        ( _____ )(  ___  )(  ____ \\__   __/(  ____ \(  ___  )( \         (  ____ \(  ___  )( (    /|\__   __/(  ___  )\__   __/( (    /|(  ____ \(  ____ )
        | () () || (   ) || (    \/   ) (   | (    \/| (   ) || (         | (    \/| (   ) ||  \  ( |   ) (   | (   ) |   ) (   |  \  ( || (    \/| (    )|
        | || || || (___) || |         | |   | |      | (___) || |         | |      | |   | ||   \ | |   | |   | (___) |   | |   |   \ | || (__    | (____)|
        | |(_)| ||  ___  || | ____    | |   | |      |  ___  || |         | |      | |   | || (\ \) |   | |   |  ___  |   | |   | (\ \) ||  __)   |     __)
        | |   | || (   ) || | \_  )   | |   | |      | (   ) || |         | |      | |   | || | \   |   | |   | (   ) |   | |   | | \   || (      | (\ (
        | )   ( || )   ( || (___) |___) (___| (____/\| )   ( || (____/\   | (____/\| (___) || )  \  |   | |   | )   ( |___) (___| )  \  || (____/\| ) \ \__
        |/     \||/     \|(_______)\_______/(_______/|/     \|(_______/   (_______/(_______)|/    )_)   )_(   |/     \|\_______/|/    )_)(_______/|/   \__/
        */
    bool MagicalContainer::isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    void MagicalContainer::iterfix()
    {
        // Clear the iterators
        sorted.clear();
        primes.clear();
        sidecross.clear();

        // Reserve memory
        sorted.reserve(container.size());
        primes.reserve(container.size());
        sidecross.reserve(container.size());

        for (auto iter = container.begin(); iter != container.end(); ++iter)
        {
            sorted.emplace_back(&(*iter));
            if (isPrime(*iter))
            {
                primes.emplace_back(&(*iter));
            }
        }

        for (auto start = container.begin(), end = container.end() - 1; start <= end; ++start, --end)
        {
            sidecross.emplace_back(&(*start));
            if (start != end)
            {
                sidecross.emplace_back(&(*end));
            }
        }
    }
    void MagicalContainer::addElement(int element)
    {
        container.push_back(element);
        std::sort(container.begin(), container.end());
        iterfix();
    }

    void MagicalContainer::removeElement(int element)
    {
        auto it = std::find(container.begin(), container.end(), element);
        if (it == this->container.end())
            throw runtime_error("OUT OF BOUNDS\n");
        container.erase(it);
        iterfix();
    }

    int MagicalContainer::size()
    {

        return container.size();
    }
    /* _______  _______  _______  _______  __       ______  _________ __       _______    ________ _________ _______  _______  _______ _________ _______  _______
      (  ___  )(  ____ \(  ____ \(  ____ \( (    /|(  __  \ \__   __/( (    /|(  ____ \   \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
      | (   ) || (    \/| (    \/| (    \/|  \  ( || (  \  )   ) (   |  \  ( || (    \/      ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
      | (___) || (_____ | |      | (__    |   \ | || |   ) |   | |   |   \ | || |            | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
      |  ___  |(_____  )| |      |  __)   | (\ \) || |   | |   | |   | (\ \) || | ____       | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
      | (   ) |      ) || |      | (      | | \   || |   ) |   | |   | | \   || | \_  )      | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
      | )   ( |/\____) || (____/\| (____/\| )  \  || (__/  )___) (___| )  \  || (___) |   ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
      |/     \|\_______)(_______/(_______/|/    )_)(______/ \_______/|/    )_)(_______)   \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/*/

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &AscContainer) : AscContainer(AscContainer), curr(AscContainer.sorted.begin()), currentIndex(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : AscContainer(other.AscContainer), curr(other.curr), currentIndex(other.currentIndex)
    {
        // other initialization code
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (&AscContainer != &other.AscContainer)
        {
            throw runtime_error("DIFFERENT CONTAINERS\n");
        }
        curr = other.curr;
        currentIndex = other.currentIndex;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*()
    {
        if (curr == AscContainer.sorted.end())
        {
            throw out_of_range("OutOfBounds\n");
        }
        return **curr;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (curr == AscContainer.sorted.end())
            throw runtime_error("OUTOFBOUNDS/n");
        ++curr;
        ++currentIndex;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
    {
        curr = AscContainer.sorted.begin();
        currentIndex = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
    {
        curr = AscContainer.sorted.end();
        currentIndex = AscContainer.sorted.size();
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        if (&AscContainer != &other.AscContainer)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        if (&AscContainer != &other.AscContainer)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex < other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        if (&AscContainer != &other.AscContainer)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex > other.currentIndex;
    }
    /* _______ _________ ______   _______  _______  _______  _______  _______  _______    _________ ________ _______  _______  _______ _________ _______  _______
      (  ____ \\__   __/(  __  \ (  ____ \(  ____ \(  ____ )(  ___  )(  ____ \(  ____ \   \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
      | (    \/   ) (   | (  \  )| (    \/| (    \/| (    )|| (   ) || (    \/| (    \/      ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
      | (_____    | |   | |   ) || (__    | |      | (____)|| |   | || (_____ | (_____       | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
      (_____  )   | |   | |   | ||  __)   | |      |     __)| |   | |(_____  )(_____  )      | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
            ) |   | |   | |   ) || (      | |      | (\ (   | |   | |      ) |      ) |      | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
      /\____) |___) (___| (__/  )| (____/\| (____/\| ) \ \__| (___) |/\____) |/\____) |   ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
      \_______)\_______/(______/ (_______/(_______/|/   \__/(_______)\_______)\_______)   \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/*/
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &SideCrossCont) : SideCrossCont(SideCrossCont), curr(SideCrossCont.sidecross.begin()), currentIndex(0)
    {
        // other initialization code
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : SideCrossCont(other.SideCrossCont), curr(other.curr), currentIndex(other.currentIndex)
    {
        // other initialization code
    }
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (&SideCrossCont != &other.SideCrossCont)
        {
            throw runtime_error("DIFFERENT CONTAINERS\n");
        }
        curr = other.curr;
        currentIndex = other.currentIndex;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        if (curr == SideCrossCont.sidecross.end())
        {
            throw out_of_range("OutOfBounds\n");
        }
        return **curr;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (curr == SideCrossCont.sidecross.end())
            throw runtime_error("OUTOFBOUNDS/n");
        ++curr;
        ++currentIndex;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
    {
        curr = SideCrossCont.sidecross.begin();
        currentIndex = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
    {
        curr = SideCrossCont.sidecross.end();
        currentIndex = SideCrossCont.sidecross.size();
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        if (&SideCrossCont != &other.SideCrossCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        if (&SideCrossCont != &other.SideCrossCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex < other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        if (&SideCrossCont != &other.SideCrossCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex > other.currentIndex;
    }
    /*
     _______  _______ _________ _______  _______    __________________ _______  _______  _______ _________ _______  _______
    (  ____ )(  ____ )\__   __/(       )(  ____ \   \__   __/\__   __/(  ____ \(  ____ )(  ___  )\__   __/(  ___  )(  ____ )
    | (    )|| (    )|   ) (   | () () || (    \/      ) (      ) (   | (    \/| (    )|| (   ) |   ) (   | (   ) || (    )|
    | (____)|| (____)|   | |   | || || || (__          | |      | |   | (__    | (____)|| (___) |   | |   | |   | || (____)|
    |  _____)|     __)   | |   | |(_)| ||  __)         | |      | |   |  __)   |     __)|  ___  |   | |   | |   | ||     __)
    | (      | (\ (      | |   | |   | || (            | |      | |   | (      | (\ (   | (   ) |   | |   | |   | || (\ (
    | )      | ) \ \_____) (___| )   ( || (____/\   ___) (___   | |   | (____/\| ) \ \__| )   ( |   | |   | (___) || ) \ \__
    |/       |/   \__/\_______/|/     \|(_______/   \_______/   )_(   (_______/|/   \__/|/     \|   )_(   (_______)|/   \__/
                                                                                                                       */
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &PrimeCont) : PrimeCont(PrimeCont), curr(PrimeCont.primes.begin()), currentIndex(0)
    {
        // other initialization code
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : PrimeCont(other.PrimeCont), curr(other.curr), currentIndex(other.currentIndex)
    {
        // other initialization code
    }
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (&PrimeCont != &other.PrimeCont)
        {
            throw runtime_error("DIFFERENT CONTAINERS\n");
        }
        curr = other.curr;
        currentIndex = other.currentIndex;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        if (curr == PrimeCont.primes.end())
        {
            throw runtime_error("OutOfBounds\n");
        }
        return **curr;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (curr == PrimeCont.primes.end())
            throw runtime_error("OutOfBounds/n");
        ++curr;
        ++currentIndex;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
    {
        curr = PrimeCont.primes.begin();
        currentIndex = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
    {
        curr = PrimeCont.primes.end();
        currentIndex = PrimeCont.primes.size();
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        if (&PrimeCont != &other.PrimeCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        if (&PrimeCont != &other.PrimeCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex < other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        if (&PrimeCont != &other.PrimeCont)
        {
            throw invalid_argument("Different Containers/n");
        }
        return currentIndex > other.currentIndex;
    }
} // namespace ariel