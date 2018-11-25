#include "algorithms.h"
#include <exception>

namespace binary_game {

    ///
    /// find one position in the sequence to pickup the element
    /// the stratergy is selecting the zero element first
    ///
    BinaryPos zeroFirstLookup(const BinaryArray& arr) {
        if (arr.size() < 3) return arr.end();
        auto it = arr.begin();
        auto end = arr.end();
        --end;

        bool isPrevZero = isZero(arr, it);
        bool isCurrZero = isZero(arr, ++it);

        auto thePosition = arr.end();

        while (it != end) {

            bool nexZero = isZero(arr, ++it);
            // if the curren position surround by zero
            // then it can be picked-up
            if (isPrevZero && nexZero) {
                // because it is already move to the next element
                // so, we need get the previous position
                thePosition = prev(it);
                // if the current element is zero
                // then return it intermediately
                if (isCurrZero) {
                    break;
                }
            }

            isPrevZero = isCurrZero;
            isCurrZero = nexZero;
        }
        return thePosition;
    }

    ///
    /// pickup at a specific position in the sequence
    /// @param: arr -> binary sequence
    ///         pos -> position of the sequence
    ///
    /// @return: element at the position
    ///
    BinaryElement pickup(BinaryArray& arr, BinaryPos pos) {
        if (pos == arr.begin()) throw std::exception("the first element in array cannot be picked up");
        auto end = arr.end();
        if (pos == end--) throw std::exception("the position of element is out of array");
        if (pos == end) throw std::exception("the last element in array cannot be picked up");

        if (!fastCheckPickup(arr, pos)) {
            throw std::exception("invalid pickup");
        }

        auto val = *pos;
        arr.erase(pos);
        return val;
    }
}