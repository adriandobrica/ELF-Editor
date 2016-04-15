#include "elf_file.h"

ELFFile::ELFFile(std::string &filename) : FileUnit(filename)
{
    file = new ELFIO::elfio();
    open = file->load(filename);

    /* TODO: create top-level entries */
}

ELFFile::~ELFFile()
{
    delete file;
}

bool ELFFile::getOpenStatus()
{
    return open;
}

bool ELFFile::save(std::string &filename)
{
    return file->save(filename);
}

void ELFFile::modifyHex(size_t offset, std::string &newContent) {}
