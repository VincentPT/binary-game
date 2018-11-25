#ifndef BINARY_GAME_BINARY_SEQUENCE
#define BINARY_GAME_BINARY_SEQUENCE

#include <list>
#include <memory>
#include <istream>
#include <ostream>

typedef std::list<char> SequenceList;

///
/// BinarySequence class, using for load and save the binary sequence
///
class BinarySequence final {
public:
    BinarySequence();
    ~BinarySequence();

    std::shared_ptr<std::list<char>> asList() const;
    void load(std::istream& stream);
    void save(std::ostream& stream) const;
private:
    std::shared_ptr<SequenceList> sequence_;
};

#endif //BINARY_GAME_BINARY_SEQUENCE