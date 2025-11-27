#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <string_view>
#include <utility>


std::int32_t oldest(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> & f1);
std::int32_t heaviest(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> & f1);
std::string_view get_oldest_friend(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends);
std::string_view get_heaviest_friend(const std::map<std::string, std::pair<std::int32_t, std::int32_t>> &friends);
