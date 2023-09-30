//
// Created by Даниил Виноградов on 30.09.2023.
//

#include <Foundation/Data.hpp>
#include <romfs/romfs.hpp>

Data::Data(const std::byte bytes[], std::size_t count, bool freeSource) {
    for (int i = 0; i < count; i++)
        _data.push_back(bytes[i]);

    if (freeSource)
        delete[] bytes;
}

Data::~Data() {}

int Data::count() const {
    return (int) _data.size();
}

std::byte* Data::data() const {
    return (std::byte*) _data.data();
}

std::optional<Data> Data::fromPath(std::string path) {
    auto data = romfs::get(path);

    if (data.valid()) {
        return Data(data.data(), data.size(), false);
    } else {
        return std::nullopt;
    }
}