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

#ifndef REPOSITORYUTILITY_H
#define REPOSITORYUTILITY_H

#include "base/i2-base.hpp"
#include "base/dictionary.hpp"
#include "base/array.hpp"
#include "base/value.hpp"
#include "base/string.hpp"
#include <boost/function.hpp>

namespace icinga
{

/**
 * @ingroup cli
 */
class RepositoryUtility
{
public:
	static Dictionary::Ptr GetArgumentAttributes(const std::vector<std::string>& arguments);

	static String GetRepositoryConfigPath(void);
	static String GetRepositoryObjectConfigPath(const String& type, const Dictionary::Ptr& object);
	static String GetRepositoryObjectConfigFilePath(const String& type, const Dictionary::Ptr& object);

	static String GetRepositoryChangeLogPath(void);

	static bool FilterRepositoryObjects(const String& type, const String& path);

	static void PrintObjects(std::ostream& fp, const String& type);

	static void PrintChangeLog(std::ostream& fp);

	static bool AddObject(const String& name, const String& type, const Dictionary::Ptr& attrs);
	static bool RemoveObject(const String& name, const String& type, const Dictionary::Ptr& attrs);

	static bool CheckChangeExists(const Dictionary::Ptr& change);

	static bool SetObjectAttribute(const String& name, const String& type, const String& attr, const Value& val);

	static bool CommitChangeLog(void);
	static bool ClearChangeLog(void);
	static bool ChangeLogHasPendingChanges(void);

	static std::vector<String> GetObjects(void);
private:
	RepositoryUtility(void);

	static bool RemoveObjectFileInternal(const String& path);

	static bool AddObjectInternal(const String& name, const String& type, const Dictionary::Ptr& attrs);
	static bool RemoveObjectInternal(const String& name, const String& type, const Dictionary::Ptr& attrs);
	static bool SetObjectAttributeInternal(const String& name, const String& type, const String& key,
	    const Value& val, const Dictionary::Ptr& attrs);

	/* repository.d */
	static void CollectObjects(const String& object_file, std::vector<String>& objects);
	static bool WriteObjectToRepository(const String& path, const String& name, const String& type, const Dictionary::Ptr& item);
	static Dictionary::Ptr GetObjectFromRepository(const String& filename);

	/* changelog */
	static void CollectChangeLog(const String& change_file, std::vector<String>& changelog);
	static bool WriteObjectToRepositoryChangeLog(const String& path, const Dictionary::Ptr& item);
	static Dictionary::Ptr GetObjectFromRepositoryChangeLog(const String& filename);

	static bool GetChangeLog(const boost::function<void (const Dictionary::Ptr&, const String&)>& callback);
	static void CollectChange(const Dictionary::Ptr& change, Array::Ptr& changes);
	static void CommitChange(const Dictionary::Ptr& change, const String& path);
	static void ClearChange(const Dictionary::Ptr& change, const String& path);

	static void FormatChangelogEntry(std::ostream& fp, const Dictionary::Ptr& change);

	/* config print helpers */
	static void SerializeObject(std::ostream& fp, const String& name, const String& type, const Dictionary::Ptr& object);
	static void FormatValue(std::ostream& fp, const Value& val);
	static void FormatArray(std::ostream& fp, const Array::Ptr& arr);
};

}

#endif /* REPOSITORYUTILITY_H */
