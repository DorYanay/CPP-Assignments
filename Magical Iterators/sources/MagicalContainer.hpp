#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> container;
        vector<int *> sorted;
        vector<int *> primes;
        vector<int *> sidecross;

    public:
        void addElement(int Element);
        void removeElement(int Element);
        int size();
        bool isPrime(int);
        void iterfix();
        class AscendingIterator
        {
        private:
            MagicalContainer &AscContainer;
            vector<int *>::iterator curr;
            int currentIndex;

        public:
            explicit AscendingIterator(MagicalContainer &);
            ~AscendingIterator() = default;
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator &operator=(const AscendingIterator &other);                      // Copy assignment operator
            AscendingIterator(AscendingIterator &&other) noexcept = default;                   // Move constructor
            AscendingIterator &operator=(AscendingIterator &&other) noexcept { return *this; } // Move assignment operator

            // Comparison operators
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*(); // dereference operator
            AscendingIterator &operator++();
            AscendingIterator &begin();
            AscendingIterator &end();
        };
        class SideCrossIterator
        {
        private:
            MagicalContainer &SideCrossCont;
            vector<int *>::iterator curr;
            int currentIndex;

        public:
            explicit SideCrossIterator(MagicalContainer &SideCrossCont);
            ~SideCrossIterator() = default;
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator &operator=(const SideCrossIterator &other);                      // Copy assignment operator
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;                   // Move constructor
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept { return *this; } // Move assignment operator

            // Comparison operators
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*(); // dereference operator
            SideCrossIterator &operator++();

            SideCrossIterator &begin();
            SideCrossIterator &end();
        };
        class PrimeIterator
        {
        private:
            MagicalContainer &PrimeCont;
            vector<int *>::iterator curr;
            int currentIndex;

        public:
            explicit PrimeIterator(MagicalContainer &PrimeCont);
            ~PrimeIterator() = default;
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator &operator=(const PrimeIterator &other);                      // Copy assignment operator
            PrimeIterator(PrimeIterator &&other) noexcept = default;                   // Move constructor
            PrimeIterator &operator=(PrimeIterator &&other) noexcept { return *this; } // Move assignment operator

            // Comparison operators
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*(); // dereference operator
            PrimeIterator &operator++();

            PrimeIterator &begin();
            PrimeIterator &end();
        };
    };
};