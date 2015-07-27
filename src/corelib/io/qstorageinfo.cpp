begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Ivan Komissarov<ABBAPOH@gmail.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstorageinfo.h"
end_include
begin_include
include|#
directive|include
file|"qstorageinfo_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QStorageInfo     \inmodule QtCore     \since 5.4     \brief Provides information about currently mounted storage and drives.      \ingroup io     \ingroup shared      Allows retrieving information about the volume's space, its mount point,     label, and filesystem name.      You can create an instance of QStorageInfo by passing the path to the     volume's mount point as a constructor parameter, or you can set it using     the setPath() method. The static mountedVolumes() method can be used to get the     list of all mounted filesystems.      QStorageInfo always caches the retrieved information, but you can call     refresh() to invalidate the cache.      The following example retrieves the most common information about the root     volume of the system, and prints information about it.      \snippet code/src_corelib_io_qstorageinfo.cpp 2 */
end_comment
begin_comment
comment|/*!     Constructs an empty QStorageInfo object.      Objects created with the default constructor will be invalid and therefore     not ready for use.      \sa setPath(), isReady(), isValid() */
end_comment
begin_constructor
DECL|function|QStorageInfo
name|QStorageInfo
operator|::
name|QStorageInfo
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QStorageInfoPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new QStorageInfo object that gives information about the volume     mounted at \a path.      If you pass a directory or file, the QStorageInfo object will refer to the     volume where this directory or file is located.     You can check if the created object is correct using the isValid() method.      The following example shows how to get the volume on which the application is     located. It is recommended to always check that the volume is ready and valid.      \snippet code/src_corelib_io_qstorageinfo.cpp 0      \sa setPath() */
end_comment
begin_constructor
DECL|function|QStorageInfo
name|QStorageInfo
operator|::
name|QStorageInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QStorageInfoPrivate
argument_list|)
block|{
name|setPath
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a new QStorageInfo object that gives information about the volume     containing the \a dir folder. */
end_comment
begin_constructor
DECL|function|QStorageInfo
name|QStorageInfo
operator|::
name|QStorageInfo
parameter_list|(
specifier|const
name|QDir
modifier|&
name|dir
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QStorageInfoPrivate
argument_list|)
block|{
name|setPath
argument_list|(
name|dir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a new QStorageInfo object that is a copy of the \a other QStorageInfo object. */
end_comment
begin_constructor
DECL|function|QStorageInfo
name|QStorageInfo
operator|::
name|QStorageInfo
parameter_list|(
specifier|const
name|QStorageInfo
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QStorageInfo object and frees its resources. */
end_comment
begin_destructor
DECL|function|~QStorageInfo
name|QStorageInfo
operator|::
name|~
name|QStorageInfo
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Makes a copy of the QStorageInfo object \a other and assigns it to this QStorageInfo object. */
end_comment
begin_function
DECL|function|operator =
name|QStorageInfo
modifier|&
name|QStorageInfo
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QStorageInfo
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QStorageInfo&QStorageInfo::operator=(QStorageInfo&&other)      Assigns \a other to this QStorageInfo instance. */
end_comment
begin_comment
comment|/*!     \fn void QStorageInfo::swap(QStorageInfo&other)      Swaps this volume info with \a other. This function is very fast and     never fails. */
end_comment
begin_comment
comment|/*!     Sets this QStorageInfo object to the filesystem mounted where \a path is located.      \a path can either be a root path of the filesystem, a directory, or a file     within that filesystem.      \sa rootPath() */
end_comment
begin_function
DECL|function|setPath
name|void
name|QStorageInfo
operator|::
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|rootPath
operator|==
name|path
condition|)
return|return;
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|rootPath
operator|=
name|path
expr_stmt|;
name|d
operator|->
name|doStat
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the mount point of the filesystem this QStorageInfo object     represents.      On Windows, it returns the volume letter in case the volume is not mounted to     a directory.      Note that the value returned by rootPath() is the real mount point of a     volume, and may not be equal to the value passed to the constructor or setPath()     method. For example, if you have only the root volume in the system, and     pass '/directory' to setPath(), then this method will return '/'.      \sa setPath(), device() */
end_comment
begin_function
DECL|function|rootPath
name|QString
name|QStorageInfo
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|rootPath
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the size (in bytes) available for the current user. It returns     the total size available if the user is the root user or a system administrator.      This size can be less than or equal to the free size returned by     bytesFree() function.      Returns -1 if QStorageInfo object is not valid.      \sa bytesTotal(), bytesFree() */
end_comment
begin_function
DECL|function|bytesAvailable
name|qint64
name|QStorageInfo
operator|::
name|bytesAvailable
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|bytesAvailable
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of free bytes in a volume. Note that if there are     quotas on the filesystem, this value can be larger than the value     returned by bytesAvailable().      Returns -1 if QStorageInfo object is not valid.      \sa bytesTotal(), bytesAvailable() */
end_comment
begin_function
DECL|function|bytesFree
name|qint64
name|QStorageInfo
operator|::
name|bytesFree
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|bytesFree
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the total volume size in bytes.      Returns -1 if QStorageInfo object is not valid.      \sa bytesFree(), bytesAvailable() */
end_comment
begin_function
DECL|function|bytesTotal
name|qint64
name|QStorageInfo
operator|::
name|bytesTotal
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|bytesTotal
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.6     Returns the optimal transfer block size for this filesystem.      Returns -1 if QStorageInfo could not determine the size or if the QStorageInfo     object is not valid.  */
end_comment
begin_function
DECL|function|blockSize
name|int
name|QStorageInfo
operator|::
name|blockSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|blockSize
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type name of the filesystem.      This is a platform-dependent function, and filesystem names can vary     between different operating systems. For example, on Windows filesystems     they can be named \c NTFS, and on Linux they can be named \c ntfs-3g or \c fuseblk.      \sa name() */
end_comment
begin_function
DECL|function|fileSystemType
name|QByteArray
name|QStorageInfo
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|fileSystemType
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the device for this volume.      For example, on Unix filesystems (including OS X), this returns the     devpath like \c /dev/sda0 for local storages. On Windows, it returns the UNC     path starting with \c \\\\?\\ for local storages (in other words, the volume GUID).      \sa rootPath() */
end_comment
begin_function
DECL|function|device
name|QByteArray
name|QStorageInfo
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|device
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the human-readable name of a filesystem, usually called \c label.      Not all filesystems support this feature. In this case, the value returned by     this method could be empty. An empty string is returned if the file system     does not support labels, or if no label is set.      On Linux, retrieving the volume's label requires \c udev to be present in the     system.      \sa fileSystemType() */
end_comment
begin_function
DECL|function|name
name|QString
name|QStorageInfo
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the volume's name, if available, or the root path if not. */
end_comment
begin_function
DECL|function|displayName
name|QString
name|QStorageInfo
operator|::
name|displayName
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|d
operator|->
name|name
return|;
return|return
name|d
operator|->
name|rootPath
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QStorageInfo::isRoot() const      Returns true if this QStorageInfo represents the system root volume; false     otherwise.      On Unix filesystems, the root volume is a volume mounted on \c /. On Windows,     the root volume is the volume where the OS is installed.      \sa root() */
end_comment
begin_comment
comment|/*!     Returns true if the current filesystem is protected from writing; false     otherwise. */
end_comment
begin_function
DECL|function|isReadOnly
name|bool
name|QStorageInfo
operator|::
name|isReadOnly
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|readOnly
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the current filesystem is ready to work; false otherwise. For     example, false is returned if the CD volume is not inserted.      Note that fileSystemType(), name(), bytesTotal(), bytesFree(), and     bytesAvailable() will return invalid data until the volume is ready.      \sa isValid() */
end_comment
begin_function
DECL|function|isReady
name|bool
name|QStorageInfo
operator|::
name|isReady
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|ready
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the QStorageInfo specified by rootPath exists and is mounted     correctly.      \sa isReady() */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QStorageInfo
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|valid
return|;
block|}
end_function
begin_comment
comment|/*!     Resets QStorageInfo's internal cache.      QStorageInfo caches information about storage to speed up performance.     QStorageInfo retrieves information during object construction and/or when calling     the setPath() method. You have to manually reset the cache by calling this     function to update storage information. */
end_comment
begin_function
DECL|function|refresh
name|void
name|QStorageInfo
operator|::
name|refresh
parameter_list|()
block|{
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|doStat
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the list of QStorageInfo objects that corresponds to the list of currently     mounted filesystems.      On Windows, this returns the drives visible in the \gui{My Computer} folder. On Unix     operating systems, it returns the list of all mounted filesystems (except for     pseudo filesystems).      Returns all currently mounted filesystems by default.      The example shows how to retrieve all available filesystems, skipping read-only ones.      \snippet code/src_corelib_io_qstorageinfo.cpp 1      \sa root() */
end_comment
begin_function
DECL|function|mountedVolumes
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|QStorageInfo
operator|::
name|mountedVolumes
parameter_list|()
block|{
return|return
name|QStorageInfoPrivate
operator|::
name|mountedVolumes
argument_list|()
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|QStorageInfo
argument_list|,
argument|getRoot
argument_list|,
argument|(QStorageInfoPrivate::root())
argument_list|)
end_macro
begin_comment
comment|/*!     Returns a QStorageInfo object that represents the system root volume.      On Unix systems this call returns the root ('/') volume; in Windows the volume where     the operating system is installed.      \sa isRoot() */
end_comment
begin_function
DECL|function|root
name|QStorageInfo
name|QStorageInfo
operator|::
name|root
parameter_list|()
block|{
return|return
operator|*
name|getRoot
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn inline bool operator==(const QStorageInfo&first, const QStorageInfo&second)      \relates QStorageInfo      Returns true if the \a first QStorageInfo object refers to the same drive or volume     as the \a second; otherwise it returns false.      Note that the result of comparing two invalid QStorageInfo objects is always     positive. */
end_comment
begin_comment
comment|/*!     \fn inline bool operator!=(const QStorageInfo&first, const QStorageInfo&second)      \relates QStorageInfo      Returns true if the \a first QStorageInfo object refers to a different drive or     volume than the \a second; otherwise returns false. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
