#ifndef BINARY_GAME_ALGORITHMS
#define BINARY_GAME_ALGORITHMS
#include <list>

namespace binary_game {
    typedef char BinaryElement;
    typedef std::list<BinaryElement> BinaryArray;
    typedef BinaryArray::const_iterator BinaryPos;

    bool inline isZero(const BinaryArray& arr, const BinaryPos& pos) {
        return *pos == 0;
    }
    auto inline prev(BinaryPos pos) {
        return --pos;
    }

    auto inline next(BinaryPos pos) {
        return ++pos;
    }

    bool inline fastCheckPickup(BinaryArray& arr, BinaryPos pos) {
        return isZero(arr, prev(pos)) && isZero(arr, next(pos));
    }
    ///
    /// find one position in the sequence to pickup the element.
    /// the stratergy is selecting the zero element first.
    /// @params: arr -> binary sequence
    /// @return: position for picking up
    ///
    BinaryPos zeroFirstLookup(const BinaryArray& arr);

    ///
    /// pickup at a specific position in the sequence
    /// @param: arr -> binary sequence
    ///         pos -> position of the sequence
    ///
    /// @return: element at the position
    ///
    BinaryElement pickup(BinaryArray& arr, BinaryPos pos);
}


#endif //BINARY_GAME_ALGORITHMS