//
// Created by Даниил Виноградов on 30.09.2023.
//

#pragma once

#include <string>
#include <optional>
#include <vector>

class Data {
public:
    [[nodiscard]] int count() const;
    [[nodiscard]] std::byte* data() const;

    Data(const std::byte* bytes, std::size_t count, bool freeSource = false);
    ~Data();

    static std::optional<Data> fromPath(std::string path);
private:
    std::vector<std::byte> _data;
};