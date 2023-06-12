#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> elements;

        // Helper function to check if a number is prime
        bool isPrime(int num);

    public:
        // Add an element to the container
        void addElement(int element);

        // Remove an element from the container
        void removeElement(int element);

        // Get the size of the container
        int size();

        // Iterator for iterating over the elements in ascending order
        class AscendingIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            AscendingIterator(MagicalContainer& cont);

            int operator*();

            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;

            bool operator!=(const AscendingIterator& other) const;

            AscendingIterator end();
        };

        // Iterator for iterating over the elements in side-cross order
        class SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t frontIndex;
            size_t backIndex;
            bool front;

        public:
            SideCrossIterator(MagicalContainer& cont);

            int operator*();

            SideCrossIterator& operator++();

            bool operator==(const SideCrossIterator& other) const;

            bool operator!=(const SideCrossIterator& other) const;

            SideCrossIterator end();
        };

        // Iterator for iterating over the prime numbers in the container
        class PrimeIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            PrimeIterator(MagicalContainer& cont);

            int operator*();

            PrimeIterator& operator++();

            bool operator==(const PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const;

            PrimeIterator end();
        };
    };

} // namespace ariel
