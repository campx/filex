#pragma once
#include <filex/FileSystem.h>

namespace filex
{

class DirectoryEntry
{
public: /** Constructors */
    DirectoryEntry() noexcept = default;
    DirectoryEntry(const DirectoryEntry&) = default;
    DirectoryEntry(DirectoryEntry&&) noexcept = default;
    DirectoryEntry(const FileSystem& filesystem, Path p);
    ~DirectoryEntry() = default;

public: /** Modifiers */
    DirectoryEntry& operator=(const DirectoryEntry&) = default;
    DirectoryEntry& operator=(DirectoryEntry&&) noexcept = default;
    void assign(const Path& p);
    void replace_filename(const Path& p);

public: /** Accessors */
    const Path& path() const noexcept;
    operator const Path&() const noexcept;
    FileStatus status() const;
    FileStatus symlink_status() const;

public: /** Operators */
    bool operator<(const DirectoryEntry& rhs) const noexcept;
    bool operator==(const DirectoryEntry& rhs) const noexcept;
    bool operator!=(const DirectoryEntry& rhs) const noexcept;
    bool operator<=(const DirectoryEntry& rhs) const noexcept;
    bool operator>(const DirectoryEntry& rhs) const noexcept;
    bool operator>=(const DirectoryEntry& rhs) const noexcept;

private: /** Data */
    const FileSystem* filesystem_;
    Path p_;
};

} // namespace filex
