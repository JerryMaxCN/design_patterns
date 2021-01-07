#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include "beverage.hpp"

namespace design_patterns {

namespace decorator_pattern {

class CondimentDecorator : public Beverage {
public:
    virtual ~CondimentDecorator() {}
};

} // namespace decorator_pattern

} // namespace design_patterns

#endif
