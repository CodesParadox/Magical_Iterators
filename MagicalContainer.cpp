#include "MagicalContainer.hpp"

namespace ariel {

    // Helper function to check if a number is prime
    bool MagicalContainer::isPrime(int num) {
        if (num < 2) {
            return false;
        }

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        } else {
            throw std::runtime_error("Element not found in the container.");
        }
    }

    // Get the size of the container
    int MagicalContainer::size() {
        return elements.size();
    }

    // AscendingIterator constructor
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : container(cont), index(0) {}

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() {
        return container.elements[index];
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++index;
        return *this;
    }

    // Equality operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &container == &(other.container) && index == other.index;
    }

    // Inequality operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    // End iterator for AscendingIterator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator endIter = *this;
        endIter.index = container.size();
        return endIter;
    }

    // SideCrossIterator constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : container(cont), frontIndex(0), backIndex(cont.size() - 1), front(true) {}

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() {
        if (front) {
            return container.elements[frontIndex];
        } else {
            return container.elements[backIndex];
        }
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (front) {
            ++frontIndex;
            front = false;
        } else {
            --backIndex;
            front = true;
        }
        return *this;
    }

    // Equality operator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return &container == &(other.container) && frontIndex == other.frontIndex && backIndex == other.backIndex && front == other.front;
    }

    // Inequality operator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    // End iterator for SideCrossIterator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator endIter = *this;
        endIter.frontIndex = container.size();
        endIter.backIndex = container.size();
        return endIter;
    }

    // PrimeIterator constructor
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : container(cont), index(0) {}

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() {
        return container.elements[index];
    }

    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        do {
            ++index;
        } while (index < container.size() && !isPrime(container.elements[index]));
        return *this;
    }

    // Equality operator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &container == &(other.container) && index == other.index;
    }

    // Inequality operator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    // End iterator for PrimeIterator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator endIter = *this;
        endIter.index = container.size();
        return endIter;
    }

} // namespace ariel
