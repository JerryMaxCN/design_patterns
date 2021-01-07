#ifndef DISPLAY_HPP
#define DISPLAY_HPP

namespace design_patterns {

namespace observer_pattern {

class IDisplay {
public:
    virtual ~IDisplay() {}

    virtual void display() const = 0;
};

} // namespace observer_pattern

} // namespace design_patterns

#endif
