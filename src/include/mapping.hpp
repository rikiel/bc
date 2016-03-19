/*
 * File: mapping.hpp
 *
 * Copyright (C) 2015 Richard Eliáš <richard.elias@matfyz.cz>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#ifndef MAPPING_HPP
#define MAPPING_HPP

#include "types.hpp"
#include "rna_tree.hpp"

class mapping
{
public:
    typedef std::vector<size_t> indexes;

    struct mapping_pair
    {
        size_t from, to;

        bool operator< (const mapping_pair& other) const;
    };

private:
    static mapping read_mapping(
                std::istream& in);
    static mapping_pair split(
                const std::string& text);

public:
    mapping() = default;

    indexes get_to_insert() const;
    indexes get_to_remove() const;

public:
    size_t distance;
    std::vector<mapping_pair> map;
};


#endif /* !MAPPING_HPP */

