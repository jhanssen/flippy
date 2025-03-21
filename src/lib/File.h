#pragma once

#include <Result.h>
#include <limits>
#include <vector>
#include <cstddef>
#include <cstdint>

class Entry;
class Directory;

class File
{
public:
    virtual ~File() = 0;

    virtual Result<std::size_t> size() const = 0;
    virtual Result<std::vector<uint8_t>> read(std::size_t offset = 0, std::size_t size = std::numeric_limits<std::size_t>::max()) const = 0;
    virtual Result<std::size_t>write(std::size_t offset, const std::vector<uint8_t>& data) = 0;
    virtual Result<void> close() = 0;

private:
    File() { }

    friend class Entry;
    friend class Directory;
};
