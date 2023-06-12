#ifndef MAGICALITERATOR_HPP
#define MAGICALITERATOR_HPP

#include <iterator>
#include <vector>

class MagicalContainer; // Forward declaration of MagicalContainer class

// AscendingIterator for iterating over elements in ascending order
class AscendingIterator : public std::iterator<std::input_iterator_tag, int> {
private:
    const MagicalContainer& container;
    size_t currentIndex;

public:
    explicit AscendingIterator(const MagicalContainer& c, size_t index);

    AscendingIterator& operator++();
    AscendingIterator operator++(int);
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    int operator*() const;
};

// SideCrossIterator for iterating over elements in a side-cross pattern
class SideCrossIterator : public std::iterator<std::input_iterator_tag, int> {
private:
    const MagicalContainer& container;
    size_t currentIndex;
    bool goRight;
    bool goUp;

public:
    explicit SideCrossIterator(const MagicalContainer& c, size_t index);

    SideCrossIterator& operator++();
    SideCrossIterator operator++(int);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    int operator*() const;
};

// PrimeIterator for iterating over prime numbers in the container
class PrimeIterator : public std::iterator<std::input_iterator_tag, int> {
private:
    const MagicalContainer& container;
    size_t currentIndex;

    bool isPrime(int num) const;

public:
    explicit PrimeIterator(const MagicalContainer& c, size_t index);

    PrimeIterator& operator++();
    PrimeIterator operator++(int);
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    int operator*() const;
};

#endif  // MAGICALITERATOR_HPP
