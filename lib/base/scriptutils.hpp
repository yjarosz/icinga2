/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef SCRIPTUTILS_H
#define SCRIPTUTILS_H

#include "base/i2-base.hpp"
#include "base/string.hpp"
#include "base/array.hpp"
#include "base/dictionary.hpp"
#include "base/type.hpp"
#include "base/dynamicobject.hpp"

namespace icinga
{

/**
 * @ingroup base
 */
class I2_BASE_API ScriptUtils
{
public:
	static String CastString(const Value& value);
	static double CastNumber(const Value& value);
	static bool CastBool(const Value& value);
	static bool Regex(const String& pattern, const String& text);
	static int Len(const Value& value);
	static Array::Ptr Union(const std::vector<Value>& arguments);
	static Array::Ptr Intersection(const std::vector<Value>& arguments);
	static void Log(const std::vector<Value>& arguments);
	static Array::Ptr Range(const std::vector<Value>& arguments);
	static Type::Ptr TypeOf(const Value& value);
	static Array::Ptr Keys(const Dictionary::Ptr& dict);
	static DynamicObject::Ptr GetObject(const String& type, const String& name);
	static void Assert(const Value& arg);

private:
	ScriptUtils(void);
};

}

#endif /* SCRIPTUTILS_H */
