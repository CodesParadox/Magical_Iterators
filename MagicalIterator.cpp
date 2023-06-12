#include "MagicalIterator.hpp"
#include "MagicalContainer.hpp"

// AscendingIterator implementation

AscendingIterator::AscendingIterator(const MagicalContainer& c, size_t index)
    : container(c), currentIndex(index) {}

AscendingIterator& AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

AscendingIterator AscendingIterator::operator++(int) {
    AscendingIterator temp = *this;
    ++(*this);
    return temp;
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return currentIndex == other.currentIndex;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

int AscendingIterator::operator*() const {
    return container.getElements()[currentIndex];
}

// SideCrossIterator implementation

SideCrossIterator::SideCrossIterator(const MagicalContainer& c, size_t index)
    : container(c), currentIndex(index), goRight(true), goUp(true) {}

SideCrossIterator& SideCrossIterator::operator++() {
    if (goRight && goUp) {
        if (currentIndex < container.getSize() - 1)
            ++currentIndex;
        else
            goRight = false;
    } else if (!goRight && goUp) {
        if (currentIndex >= container.getWidth())
            currentIndex -= container.getWidth();
        else
            goUp = false;
    } else if (!goRight && !goUp) {
        if (currentIndex > 0)
            --currentIndex;
        else
            goRight = true;
    } else if (goRight && !goUp) {
        if (currentIndex < container.getSize() - container.getWidth())
            currentIndex += container.getWidth();
        else
            goUp = true;
    }

    return *this;
}

SideCrossIterator SideCrossIterator::operator++(int) {
    SideCrossIterator temp = *this;
    ++(*this);
    return temp;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return currentIndex == other.currentIndex;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

int SideCrossIterator::operator*() const {
    return container.getElements()[currentIndex];
}

// PrimeIterator implementation

PrimeIterator::PrimeIterator(const MagicalContainer& c, size_t index)
    : container(c), currentIndex(index) {}

bool PrimeIterator::isPrime(int num) const {
    if (num < 2)
        return false;

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

PrimeIterator& PrimeIterator::operator++() {
    ++currentIndex;

    while (currentIndex < container.getSize() && !isPrime(container.getElements()[currentIndex])) {
        ++currentIndex;
    }

    return *this;
}

PrimeIterator PrimeIterator::operator++(int) {
    PrimeIterator temp = *this;
    ++(*this);
    return temp;
}

bool PrimeIterator::operator==(const PrimeIterator& other) const {
    return currentIndex == other.currentIndex;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

int PrimeIterator::operator*() const {
    return container.getElements()[currentIndex];
}
