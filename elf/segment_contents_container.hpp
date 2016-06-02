/* The MIT License (MIT)
 *
 * Copyright (c) 2016 Ștefan-Gabriel Mirea, Adrian Dobrică
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SEGMENT_CONTENTS_CONTAINER_HPP_
#define SEGMENT_CONTENTS_CONTAINER_HPP_

#include "container.hpp"
#include "elf_code_container.hpp"
#include "elf_file.hpp"

namespace elf
{
/**
 * Container used to access the actual segments in the file. Since segments in the input file will
 * probably be separated by inactive space or even by the section header table, this container does
 * not represent a contiguous interval in the file.
 */
class SegmentContentsContainer : public Container
{
public:
    SegmentContentsContainer(ELFFile *file);
    std::vector<Container *> &getInnerContainers();
    ~SegmentContentsContainer();
};
}

#endif // SEGMENT_CONTENTS_CONTAINER_HPP_
