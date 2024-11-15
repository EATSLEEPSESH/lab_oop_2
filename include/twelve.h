#ifndef TWELVE_H
#define TWELVE_H

#include <string>
#include <initializer_list>
#include <stdexcept>

class Twelve {
private:
    unsigned char *digits;
    size_t size;

public:

    Twelve();

    explicit Twelve(const size_t &n, unsigned char t = 0);

    Twelve(const std::initializer_list<unsigned char> &t);

    explicit Twelve(const std::string &t);

    Twelve(const Twelve &other);

    Twelve(Twelve &&other) noexcept;

    virtual ~Twelve() noexcept;

    size_t getSize() const;

    [[nodiscard]] unsigned char getDigit(size_t index) const;

    Twelve add(const Twelve &other) const;

    Twelve subtract(const Twelve &other) const;

    bool isBiggerThan(const Twelve &other) const;

    bool isLessThan(const Twelve &other) const;

    bool isEqual(const Twelve &other) const;

    std::string toString() const;
};

#endif