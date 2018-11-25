#include "BinarySequence.h"
#include <string>
#include <sstream>

using namespace std;

BinarySequence::BinarySequence() {
    sequence_ = make_shared<SequenceList>();
}

BinarySequence::~BinarySequence() {

}

shared_ptr<SequenceList> BinarySequence::asList() const {
    return sequence_;
}

void BinarySequence::load(istream& stream) {

    // read number of element in the sequence
    int elementCount;

    string str;
    std::getline(stream, str);
    elementCount = atoi(str.c_str());

    // read elements
    std::getline(stream, str);
    stringstream ss(str);
    unsigned int element;
    for (int i = 0; (i < elementCount) && !ss.eof(); ++i) {
        ss >> element;
        if (element > 1) {
            throw exception("invalid element");
        }
        sequence_->push_back((char) element);
    }

    // check if invalid data
    if (elementCount > (int)sequence_->size()) {
        throw exception("sequence is lacking");
    }
}

void BinarySequence::save(ostream& stream) const {
    // write number of element
    stream << sequence_->size() << endl;

    // write element
    for (auto it = sequence_->begin(); it != sequence_->end(); ++it) {
        stream << (int)*it << ' ';
    }
}