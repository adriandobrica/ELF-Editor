#include "elf_header_container.hpp"

using namespace elf;

ELFHeaderContainer::ELFHeaderContainer(ELFFile *file, const std::pair<int, int> &interval) :
    Container(file, true, interval)
{
    setName("ELF Header");
}

std::vector<Container *> &ELFHeaderContainer::getInnerContainers()
{
    if (innerContainers.empty())
    {
        Container *container;

        container = new Container(getFile(), false);
        container->setName("e_ident");
        addInnerContainer(container);

        container = new Container(getFile(), false);
        container->setName("co");
        addInnerContainer(container);
    }
    return innerContainers;
}

ELFHeaderContainer::~ELFHeaderContainer() {}