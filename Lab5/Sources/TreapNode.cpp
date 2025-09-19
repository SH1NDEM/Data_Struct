#include "TreapNode.h"

TreapNode::TreapNode(int k) : Key(k), Priority(rand()), Left(nullptr), Right(nullptr) {}