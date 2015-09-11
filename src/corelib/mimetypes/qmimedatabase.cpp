begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2015 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author David Faure<david.faure@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_comment
comment|// always first
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_MIMETYPE
end_ifndef
begin_include
include|#
directive|include
file|"qmimedatabase.h"
end_include
begin_include
include|#
directive|include
file|"qmimedatabase_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimeprovider_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimetype_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStack>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC
argument_list|(
name|QMimeDatabasePrivate
argument_list|,
name|staticQMimeDatabase
argument_list|)
DECL|function|instance
name|QMimeDatabasePrivate
modifier|*
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
argument_list|{     return
name|staticQMimeDatabase
argument_list|()
argument_list|; }
DECL|function|QMimeDatabasePrivate
name|QMimeDatabasePrivate
operator|::
name|QMimeDatabasePrivate
argument_list|()
range|:
name|m_provider
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|m_defaultMimeType
argument_list|(
name|QLatin1String
argument_list|(
literal|"application/octet-stream"
argument_list|)
argument_list|)
argument_list|{ }
DECL|function|~QMimeDatabasePrivate
name|QMimeDatabasePrivate
operator|::
name|~
name|QMimeDatabasePrivate
argument_list|()
argument_list|{
operator|delete
name|m_provider
argument_list|;
name|m_provider
operator|=
literal|0
argument_list|; }
DECL|function|provider
name|QMimeProviderBase
modifier|*
name|QMimeDatabasePrivate
operator|::
name|provider
argument_list|()
argument_list|{     if
operator|(
operator|!
name|m_provider
operator|)
block|{
name|QMimeProviderBase
operator|*
name|binaryProvider
operator|=
operator|new
name|QMimeBinaryProvider
argument_list|(
name|this
argument_list|)
block|;
if|if
condition|(
name|binaryProvider
operator|->
name|isValid
argument_list|()
condition|)
block|{
name|m_provider
operator|=
name|binaryProvider
block|;         }
else|else
block|{
operator|delete
name|binaryProvider
block|;
name|m_provider
operator|=
operator|new
name|QMimeXMLProvider
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
expr|}
return|return
name|m_provider
return|;
end_decl_stmt
begin_macro
unit|}  void
DECL|function|setProvider
name|QMimeDatabasePrivate
end_macro
begin_expr_stmt
DECL|function|setProvider
operator|::
name|setProvider
operator|(
name|QMimeProviderBase
operator|*
name|theProvider
operator|)
block|{
operator|delete
name|m_provider
block|;
name|m_provider
operator|=
name|theProvider
block|; }
comment|/*!     \internal     Returns a MIME type or an invalid one if none found  */
DECL|function|mimeTypeForName
name|QMimeType
name|QMimeDatabasePrivate
operator|::
name|mimeTypeForName
operator|(
specifier|const
name|QString
operator|&
name|nameOrAlias
operator|)
block|{
return|return
name|provider
argument_list|()
operator|->
name|mimeTypeForName
argument_list|(
name|provider
argument_list|()
operator|->
name|resolveAlias
argument_list|(
name|nameOrAlias
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|mimeTypeForFileName
name|QStringList
name|QMimeDatabasePrivate
operator|::
name|mimeTypeForFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QString
modifier|*
name|foundSuffix
parameter_list|)
block|{
if|if
condition|(
name|fileName
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
return|return
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"inode/directory"
argument_list|)
return|;
specifier|const
name|QStringList
name|matchingMimeTypes
init|=
name|provider
argument_list|()
operator|->
name|findByFileName
argument_list|(
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|fileName
argument_list|()
argument_list|,
name|foundSuffix
argument_list|)
decl_stmt|;
return|return
name|matchingMimeTypes
return|;
block|}
end_function
begin_function
DECL|function|isTextFile
specifier|static
specifier|inline
name|bool
name|isTextFile
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
comment|// UTF16 byte order marks
specifier|static
specifier|const
name|char
name|bigEndianBOM
index|[]
init|=
literal|"\xFE\xFF"
decl_stmt|;
specifier|static
specifier|const
name|char
name|littleEndianBOM
index|[]
init|=
literal|"\xFF\xFE"
decl_stmt|;
if|if
condition|(
name|data
operator|.
name|startsWith
argument_list|(
name|bigEndianBOM
argument_list|)
operator|||
name|data
operator|.
name|startsWith
argument_list|(
name|littleEndianBOM
argument_list|)
condition|)
return|return
literal|true
return|;
comment|// Check the first 32 bytes (see shared-mime spec)
specifier|const
name|char
modifier|*
name|p
init|=
name|data
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|e
init|=
name|p
operator|+
name|qMin
argument_list|(
literal|32
argument_list|,
name|data
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|p
operator|<
name|e
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|*
name|p
argument_list|)
operator|<
literal|32
operator|&&
operator|*
name|p
operator|!=
literal|9
operator|&&
operator|*
name|p
operator|!=
literal|10
operator|&&
operator|*
name|p
operator|!=
literal|13
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|findByData
name|QMimeType
name|QMimeDatabasePrivate
operator|::
name|findByData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|int
modifier|*
name|accuracyPtr
parameter_list|)
block|{
if|if
condition|(
name|data
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
operator|*
name|accuracyPtr
operator|=
literal|100
expr_stmt|;
return|return
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"application/x-zerosize"
argument_list|)
argument_list|)
return|;
block|}
operator|*
name|accuracyPtr
operator|=
literal|0
expr_stmt|;
name|QMimeType
name|candidate
init|=
name|provider
argument_list|()
operator|->
name|findByMagic
argument_list|(
name|data
argument_list|,
name|accuracyPtr
argument_list|)
decl_stmt|;
if|if
condition|(
name|candidate
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|candidate
return|;
if|if
condition|(
name|isTextFile
argument_list|(
name|data
argument_list|)
condition|)
block|{
operator|*
name|accuracyPtr
operator|=
literal|5
expr_stmt|;
return|return
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
return|;
block|}
return|return
name|mimeTypeForName
argument_list|(
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mimeTypeForFileNameAndData
name|QMimeType
name|QMimeDatabasePrivate
operator|::
name|mimeTypeForFileNameAndData
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QIODevice
modifier|*
name|device
parameter_list|,
name|int
modifier|*
name|accuracyPtr
parameter_list|)
block|{
comment|// First, glob patterns are evaluated. If there is a match with max weight,
comment|// this one is selected and we are done. Otherwise, the file contents are
comment|// evaluated and the match with the highest value (either a magic priority or
comment|// a glob pattern weight) is selected. Matching starts from max level (most
comment|// specific) in both cases, even when there is already a suffix matching candidate.
operator|*
name|accuracyPtr
operator|=
literal|0
expr_stmt|;
comment|// Pass 1) Try to match on the file name
name|QStringList
name|candidatesByName
init|=
name|mimeTypeForFileName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|candidatesByName
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
operator|*
name|accuracyPtr
operator|=
literal|100
expr_stmt|;
specifier|const
name|QMimeType
name|mime
init|=
name|mimeTypeForName
argument_list|(
name|candidatesByName
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mime
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|mime
return|;
name|candidatesByName
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// Extension is unknown, or matches multiple mimetypes.
comment|// Pass 2) Match on content, if we can read the data
if|if
condition|(
name|device
operator|->
name|isOpen
argument_list|()
condition|)
block|{
comment|// Read 16K in one go (QIODEVICE_BUFFERSIZE in qiodevice_p.h).
comment|// This is much faster than seeking back and forth into QIODevice.
specifier|const
name|QByteArray
name|data
init|=
name|device
operator|->
name|peek
argument_list|(
literal|16384
argument_list|)
decl_stmt|;
name|int
name|magicAccuracy
init|=
literal|0
decl_stmt|;
name|QMimeType
name|candidateByData
argument_list|(
name|findByData
argument_list|(
name|data
argument_list|,
operator|&
name|magicAccuracy
argument_list|)
argument_list|)
decl_stmt|;
comment|// Disambiguate conflicting extensions (if magic matching found something)
if|if
condition|(
name|candidateByData
operator|.
name|isValid
argument_list|()
operator|&&
name|magicAccuracy
operator|>
literal|0
condition|)
block|{
comment|// "for glob_match in glob_matches:"
comment|// "if glob_match is subclass or equal to sniffed_type, use glob_match"
specifier|const
name|QString
name|sniffedMime
init|=
name|candidateByData
operator|.
name|name
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|m
decl|,
name|candidatesByName
control|)
block|{
if|if
condition|(
name|inherits
argument_list|(
name|m
argument_list|,
name|sniffedMime
argument_list|)
condition|)
block|{
comment|// We have magic + pattern pointing to this, so it's a pretty good match
operator|*
name|accuracyPtr
operator|=
literal|100
expr_stmt|;
return|return
name|mimeTypeForName
argument_list|(
name|m
argument_list|)
return|;
block|}
block|}
operator|*
name|accuracyPtr
operator|=
name|magicAccuracy
expr_stmt|;
return|return
name|candidateByData
return|;
block|}
block|}
if|if
condition|(
name|candidatesByName
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
block|{
operator|*
name|accuracyPtr
operator|=
literal|20
expr_stmt|;
name|candidatesByName
operator|.
name|sort
argument_list|()
expr_stmt|;
comment|// to make it deterministic
specifier|const
name|QMimeType
name|mime
init|=
name|mimeTypeForName
argument_list|(
name|candidatesByName
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mime
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|mime
return|;
block|}
return|return
name|mimeTypeForName
argument_list|(
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|allMimeTypes
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|QMimeDatabasePrivate
operator|::
name|allMimeTypes
parameter_list|()
block|{
return|return
name|provider
argument_list|()
operator|->
name|allMimeTypes
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|inherits
name|bool
name|QMimeDatabasePrivate
operator|::
name|inherits
parameter_list|(
specifier|const
name|QString
modifier|&
name|mime
parameter_list|,
specifier|const
name|QString
modifier|&
name|parent
parameter_list|)
block|{
specifier|const
name|QString
name|resolvedParent
init|=
name|provider
argument_list|()
operator|->
name|resolveAlias
argument_list|(
name|parent
argument_list|)
decl_stmt|;
comment|//Q_ASSERT(provider()->resolveAlias(mime) == mime);
name|QStack
argument_list|<
name|QString
argument_list|>
name|toCheck
decl_stmt|;
name|toCheck
operator|.
name|push
argument_list|(
name|mime
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|toCheck
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|current
init|=
name|toCheck
operator|.
name|pop
argument_list|()
decl_stmt|;
if|if
condition|(
name|current
operator|==
name|resolvedParent
condition|)
return|return
literal|true
return|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|par
decl|,
name|provider
argument_list|()
operator|->
name|parents
argument_list|(
name|current
argument_list|)
control|)
name|toCheck
operator|.
name|push
argument_list|(
name|par
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \class QMimeDatabase     \inmodule QtCore     \brief The QMimeDatabase class maintains a database of MIME types.      \since 5.0      The MIME type database is provided by the freedesktop.org shared-mime-info     project. If the MIME type database cannot be found on the system, as is the case     on most Windows, OS X, and iOS systems, Qt will use its own copy of it.      Applications which want to define custom MIME types need to install an     XML file into the locations searched for MIME definitions.     These locations can be queried with     \code     QStandardPaths::locateAll(QStandardPaths::GenericDataLocation, QLatin1String("mime/packages"),                               QStandardPaths::LocateDirectory);     \endcode     On a typical Unix system, this will be /usr/share/mime/packages/, but it is also     possible to extend the list of directories by setting the environment variable     \c XDG_DATA_DIRS. For instance adding /opt/myapp/share to \c XDG_DATA_DIRS will result     in /opt/myapp/share/mime/packages/ being searched for MIME definitions.      Here is an example of MIME XML:     \code<?xml version="1.0" encoding="UTF-8"?><mime-info xmlns="http://www.freedesktop.org/standards/shared-mime-info"><mime-type type="application/vnd.nokia.qt.qmakeprofile"><comment xml:lang="en">Qt qmake Profile</comment><glob pattern="*.pro" weight="50"/></mime-type></mime-info>     \endcode      For more details about the syntax of XML MIME definitions, including defining     "magic" in order to detect MIME types based on data as well, read the     Shared Mime Info specification at     http://standards.freedesktop.org/shared-mime-info-spec/shared-mime-info-spec-latest.html      On Unix systems, a binary cache is used for more performance. This cache is generated     by the command "update-mime-database path", where path would be /opt/myapp/share/mime     in the above example. Make sure to run this command when installing the MIME type     definition file.      \threadsafe      \snippet code/src_corelib_mimetype_qmimedatabase.cpp 0      \sa QMimeType  */
end_comment
begin_comment
comment|/*!     \fn QMimeDatabase::QMimeDatabase();     Constructs a QMimeDatabase object.      It is perfectly OK to create an instance of QMimeDatabase every time you need to     perform a lookup.     The parsing of mimetypes is done on demand (when shared-mime-info is installed)     or when the very first instance is constructed (when parsing XML files directly).  */
end_comment
begin_constructor
DECL|function|QMimeDatabase
name|QMimeDatabase
operator|::
name|QMimeDatabase
parameter_list|()
member_init_list|:
name|d
argument_list|(
name|staticQMimeDatabase
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QMimeDatabase::~QMimeDatabase();     Destroys the QMimeDatabase object.  */
end_comment
begin_destructor
DECL|function|~QMimeDatabase
name|QMimeDatabase
operator|::
name|~
name|QMimeDatabase
parameter_list|()
block|{
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn QMimeType QMimeDatabase::mimeTypeForName(const QString&nameOrAlias) const;     Returns a MIME type for \a nameOrAlias or an invalid one if none found.  */
end_comment
begin_function
DECL|function|mimeTypeForName
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForName
parameter_list|(
specifier|const
name|QString
modifier|&
name|nameOrAlias
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|nameOrAlias
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for \a fileInfo.      A valid MIME type is always returned.      The default matching algorithm looks at both the file name and the file     contents, if necessary. The file extension has priority over the contents,     but the contents will be used if the file extension is unknown, or     matches multiple MIME types.     If \a fileInfo is a Unix symbolic link, the file that it refers to     will be used instead.     If the file doesn't match any known pattern or data, the default MIME type     (application/octet-stream) is returned.      When \a mode is set to MatchExtension, only the file name is used, not     the file contents. The file doesn't even have to exist. If the file name     doesn't match any known pattern, the default MIME type (application/octet-stream)     is returned.     If multiple MIME types match this file, the first one (alphabetically) is returned.      When \a mode is set to MatchContent, and the file is readable, only the     file contents are used to determine the MIME type. This is equivalent to     calling mimeTypeForData with a QFile as input device.      \a fileInfo may refer to an absolute or relative path.      \sa QMimeType::isDefault(), mimeTypeForData() */
end_comment
begin_function
DECL|function|mimeTypeForFile
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForFile
parameter_list|(
specifier|const
name|QFileInfo
modifier|&
name|fileInfo
parameter_list|,
name|MatchMode
name|mode
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileInfo
operator|.
name|isDir
argument_list|()
condition|)
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"inode/directory"
argument_list|)
argument_list|)
return|;
name|QFile
name|file
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_UNIX
comment|// Cannot access statBuf.st_mode from the filesystem engine, so we have to stat again.
specifier|const
name|QByteArray
name|nativeFilePath
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QT_STATBUF
name|statBuffer
decl_stmt|;
if|if
condition|(
name|QT_LSTAT
argument_list|(
name|nativeFilePath
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|statBuffer
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|S_ISCHR
argument_list|(
name|statBuffer
operator|.
name|st_mode
argument_list|)
condition|)
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"inode/chardevice"
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|S_ISBLK
argument_list|(
name|statBuffer
operator|.
name|st_mode
argument_list|)
condition|)
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"inode/blockdevice"
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|S_ISFIFO
argument_list|(
name|statBuffer
operator|.
name|st_mode
argument_list|)
condition|)
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"inode/fifo"
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|S_ISSOCK
argument_list|(
name|statBuffer
operator|.
name|st_mode
argument_list|)
condition|)
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|QLatin1String
argument_list|(
literal|"inode/socket"
argument_list|)
argument_list|)
return|;
block|}
endif|#
directive|endif
name|int
name|priority
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|MatchDefault
case|:
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
comment|// isOpen() will be tested by method below
return|return
name|d
operator|->
name|mimeTypeForFileNameAndData
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
operator|&
name|file
argument_list|,
operator|&
name|priority
argument_list|)
return|;
case|case
name|MatchExtension
case|:
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return
name|mimeTypeForFile
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|mode
argument_list|)
return|;
case|case
name|MatchContent
case|:
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
return|return
name|mimeTypeForData
argument_list|(
operator|&
name|file
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|d
operator|->
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|d
operator|->
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for the file named \a fileName using \a mode.      \overload */
end_comment
begin_function
DECL|function|mimeTypeForFile
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|MatchMode
name|mode
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mode
operator|==
name|MatchExtension
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QStringList
name|matches
init|=
name|d
operator|->
name|mimeTypeForFileName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|int
name|matchCount
init|=
name|matches
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|matchCount
operator|==
literal|0
condition|)
block|{
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|d
operator|->
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|matchCount
operator|==
literal|1
condition|)
block|{
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|matches
operator|.
name|first
argument_list|()
argument_list|)
return|;
block|}
else|else
block|{
comment|// We have to pick one.
name|matches
operator|.
name|sort
argument_list|()
expr_stmt|;
comment|// Make it deterministic
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|matches
operator|.
name|first
argument_list|()
argument_list|)
return|;
block|}
block|}
else|else
block|{
comment|// Implemented as a wrapper around mimeTypeForFile(QFileInfo), so no mutex.
name|QFileInfo
name|fileInfo
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
return|return
name|mimeTypeForFile
argument_list|(
name|fileInfo
argument_list|,
name|mode
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the MIME types for the file name \a fileName.      If the file name doesn't match any known pattern, an empty list is returned.     If multiple MIME types match this file, they are all returned.      This function does not try to open the file. To also use the content     when determining the MIME type, use mimeTypeForFile() or     mimeTypeForFileNameAndData() instead.      \sa mimeTypeForFile() */
end_comment
begin_function
DECL|function|mimeTypesForFileName
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|QMimeDatabase
operator|::
name|mimeTypesForFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QStringList
name|matches
init|=
name|d
operator|->
name|mimeTypeForFileName
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|mimes
decl_stmt|;
name|matches
operator|.
name|sort
argument_list|()
expr_stmt|;
comment|// Make it deterministic
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|mime
decl|,
name|matches
control|)
name|mimes
operator|.
name|append
argument_list|(
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|mime
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|mimes
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the suffix for the file \a fileName, as known by the MIME database.      This allows to pre-select "tar.bz2" for foo.tar.bz2, but still only     "txt" for my.file.with.dots.txt. */
end_comment
begin_function
DECL|function|suffixForFileName
name|QString
name|QMimeDatabase
operator|::
name|suffixForFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|QString
name|foundSuffix
decl_stmt|;
name|d
operator|->
name|mimeTypeForFileName
argument_list|(
name|fileName
argument_list|,
operator|&
name|foundSuffix
argument_list|)
expr_stmt|;
return|return
name|foundSuffix
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for \a data.      A valid MIME type is always returned. If \a data doesn't match any     known MIME type data, the default MIME type (application/octet-stream)     is returned. */
end_comment
begin_function
DECL|function|mimeTypeForData
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|int
name|accuracy
init|=
literal|0
decl_stmt|;
return|return
name|d
operator|->
name|findByData
argument_list|(
name|data
argument_list|,
operator|&
name|accuracy
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for the data in \a device.      A valid MIME type is always returned. If the data in \a device doesn't match any     known MIME type data, the default MIME type (application/octet-stream)     is returned. */
end_comment
begin_function
DECL|function|mimeTypeForData
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForData
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
name|int
name|accuracy
init|=
literal|0
decl_stmt|;
specifier|const
name|bool
name|openedByUs
init|=
operator|!
name|device
operator|->
name|isOpen
argument_list|()
operator|&&
name|device
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
if|if
condition|(
name|device
operator|->
name|isOpen
argument_list|()
condition|)
block|{
comment|// Read 16K in one go (QIODEVICE_BUFFERSIZE in qiodevice_p.h).
comment|// This is much faster than seeking back and forth into QIODevice.
specifier|const
name|QByteArray
name|data
init|=
name|device
operator|->
name|peek
argument_list|(
literal|16384
argument_list|)
decl_stmt|;
specifier|const
name|QMimeType
name|result
init|=
name|d
operator|->
name|findByData
argument_list|(
name|data
argument_list|,
operator|&
name|accuracy
argument_list|)
decl_stmt|;
if|if
condition|(
name|openedByUs
condition|)
name|device
operator|->
name|close
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
return|return
name|d
operator|->
name|mimeTypeForName
argument_list|(
name|d
operator|->
name|defaultMimeType
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for \a url.      If the URL is a local file, this calls mimeTypeForFile.      Otherwise the matching is done based on the file name only,     except for schemes where file names don't mean much, like HTTP.     This method always returns the default mimetype for HTTP URLs,     use QNetworkAccessManager to handle HTTP URLs properly.      A valid MIME type is always returned. If \a url doesn't match any     known MIME type data, the default MIME type (application/octet-stream)     is returned. */
end_comment
begin_function
DECL|function|mimeTypeForUrl
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|url
operator|.
name|isLocalFile
argument_list|()
condition|)
return|return
name|mimeTypeForFile
argument_list|(
name|url
operator|.
name|toLocalFile
argument_list|()
argument_list|)
return|;
specifier|const
name|QString
name|scheme
init|=
name|url
operator|.
name|scheme
argument_list|()
decl_stmt|;
if|if
condition|(
name|scheme
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"http"
argument_list|)
argument_list|)
condition|)
return|return
name|mimeTypeForName
argument_list|(
name|d
operator|->
name|defaultMimeType
argument_list|()
argument_list|)
return|;
return|return
name|mimeTypeForFile
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for the given \a fileName and \a device data.      This overload can be useful when the file is remote, and we started to     download some of its data in a device. This allows to do full MIME type     matching for remote files as well.      If the device is not open, it will be opened by this function, and closed     after the MIME type detection is completed.      A valid MIME type is always returned. If \a device data doesn't match any     known MIME type data, the default MIME type (application/octet-stream)     is returned.      This method looks at both the file name and the file contents,     if necessary. The file extension has priority over the contents,     but the contents will be used if the file extension is unknown, or     matches multiple MIME types. */
end_comment
begin_function
DECL|function|mimeTypeForFileNameAndData
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForFileNameAndData
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QIODevice
modifier|*
name|device
parameter_list|)
specifier|const
block|{
name|int
name|accuracy
init|=
literal|0
decl_stmt|;
specifier|const
name|bool
name|openedByUs
init|=
operator|!
name|device
operator|->
name|isOpen
argument_list|()
operator|&&
name|device
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
specifier|const
name|QMimeType
name|result
init|=
name|d
operator|->
name|mimeTypeForFileNameAndData
argument_list|(
name|fileName
argument_list|,
name|device
argument_list|,
operator|&
name|accuracy
argument_list|)
decl_stmt|;
if|if
condition|(
name|openedByUs
condition|)
name|device
operator|->
name|close
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a MIME type for the given \a fileName and device \a data.      This overload can be useful when the file is remote, and we started to     download some of its data. This allows to do full MIME type matching for     remote files as well.      A valid MIME type is always returned. If \a data doesn't match any     known MIME type data, the default MIME type (application/octet-stream)     is returned.      This method looks at both the file name and the file contents,     if necessary. The file extension has priority over the contents,     but the contents will be used if the file extension is unknown, or     matches multiple MIME types. */
end_comment
begin_function
DECL|function|mimeTypeForFileNameAndData
name|QMimeType
name|QMimeDatabase
operator|::
name|mimeTypeForFileNameAndData
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
name|QBuffer
name|buffer
argument_list|(
cast|const_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
operator|&
name|data
argument_list|)
argument_list|)
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|int
name|accuracy
init|=
literal|0
decl_stmt|;
return|return
name|d
operator|->
name|mimeTypeForFileNameAndData
argument_list|(
name|fileName
argument_list|,
operator|&
name|buffer
argument_list|,
operator|&
name|accuracy
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the list of all available MIME types.      This can be useful for showing all MIME types to the user, for instance     in a MIME type editor. Do not use unless really necessary in other cases     though, prefer using the  \l {mimeTypeForData()}{mimeTypeForXxx()} methods for performance reasons. */
end_comment
begin_function
DECL|function|allMimeTypes
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|QMimeDatabase
operator|::
name|allMimeTypes
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|allMimeTypes
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QMimeDatabase::MatchMode      This enum specifies how matching a file to a MIME type is performed.      \value MatchDefault Both the file name and content are used to look for a match      \value MatchExtension Only the file name is used to look for a match      \value MatchContent The file content is used to look for a match */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_MIMETYPE
end_comment
end_unit
