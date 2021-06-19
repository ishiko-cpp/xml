/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "Writer.h"
#include <Ishiko/FileSystem.h>

using namespace Ishiko::FileSystem;

namespace Ishiko
{
namespace XML
{

Writer::Writer()
{
}

void Writer::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    CreateEmptyFile(path, error);
}

void Writer::writeStartDocument()
{
}

void Writer::writeEndDocument()
{
}

}
}
