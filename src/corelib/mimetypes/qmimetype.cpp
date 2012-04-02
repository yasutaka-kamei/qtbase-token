begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmimetype.h"
end_include
begin_include
include|#
directive|include
file|"qmimetype_p.h"
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
file|"qmimeglobpattern_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<memory>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QMimeTypePrivate
name|QMimeTypePrivate
operator|::
name|QMimeTypePrivate
parameter_list|()
member_init_list|:
name|loaded
argument_list|(
literal|false
argument_list|)
block|{}
end_constructor
begin_constructor
DECL|function|QMimeTypePrivate
name|QMimeTypePrivate
operator|::
name|QMimeTypePrivate
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|other
parameter_list|)
member_init_list|:
name|name
argument_list|(
name|other
operator|.
name|d
operator|->
name|name
argument_list|)
member_init_list|,
name|localeComments
argument_list|(
name|other
operator|.
name|d
operator|->
name|localeComments
argument_list|)
member_init_list|,
name|genericIconName
argument_list|(
name|other
operator|.
name|d
operator|->
name|genericIconName
argument_list|)
member_init_list|,
name|iconName
argument_list|(
name|other
operator|.
name|d
operator|->
name|iconName
argument_list|)
member_init_list|,
name|globPatterns
argument_list|(
name|other
operator|.
name|d
operator|->
name|globPatterns
argument_list|)
member_init_list|,
name|loaded
argument_list|(
name|other
operator|.
name|d
operator|->
name|loaded
argument_list|)
block|{}
end_constructor
begin_function
DECL|function|clear
name|void
name|QMimeTypePrivate
operator|::
name|clear
parameter_list|()
block|{
name|name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|localeComments
operator|.
name|clear
argument_list|()
expr_stmt|;
name|genericIconName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|iconName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|globPatterns
operator|.
name|clear
argument_list|()
expr_stmt|;
name|loaded
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addGlobPattern
name|void
name|QMimeTypePrivate
operator|::
name|addGlobPattern
parameter_list|(
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
block|{
name|globPatterns
operator|.
name|append
argument_list|(
name|pattern
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QMimeType     \brief The QMimeType class describes types of file or data, represented by a MIME type string.      \since 5.0      For instance a file named "readme.txt" has the MIME type "text/plain".     The MIME type can be determined from the file name, or from the file     contents, or from both. MIME type determination can also be done on     buffers of data not coming from files.      Determining the MIME type of a file can be useful to make sure your     application supports it. It is also useful in file-manager-like applications     or widgets, in order to display an appropriate icon() for the file, or even     the descriptive comment() in detailed views.      To check if a file has the expected MIME type, you should use inherits()     rather than a simple string comparison based on the name(). This is because     MIME types can inherit from each other: for instance a C source file is     a specific type of plain text file, so text/x-csrc inherits text/plain.      \sa QMimeDatabase  */
end_comment
begin_comment
comment|/*!     \fn QMimeType::QMimeType();     Constructs this QMimeType object initialized with default property values that indicate an invalid MIME type.  */
end_comment
begin_constructor
DECL|function|QMimeType
name|QMimeType
operator|::
name|QMimeType
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QMimeTypePrivate
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QMimeType::QMimeType(const QMimeType&other);     Constructs this QMimeType object as a copy of \a other.  */
end_comment
begin_constructor
DECL|function|QMimeType
name|QMimeType
operator|::
name|QMimeType
parameter_list|(
specifier|const
name|QMimeType
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
comment|/*!     \fn QMimeType&QMimeType::operator=(const QMimeType&other);     Assigns the data of \a other to this QMimeType object, and returns a reference to this object.  */
end_comment
begin_function
DECL|function|operator =
name|QMimeType
modifier|&
name|QMimeType
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|other
parameter_list|)
block|{
if|if
condition|(
name|d
operator|!=
name|other
operator|.
name|d
condition|)
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
comment|/*!     \fn QMimeType::QMimeType(const QMimeTypePrivate&dd);     Assigns the data of the QMimeTypePrivate \a dd to this QMimeType object, and returns a reference to this object.  */
end_comment
begin_constructor
DECL|function|QMimeType
name|QMimeType
operator|::
name|QMimeType
parameter_list|(
specifier|const
name|QMimeTypePrivate
modifier|&
name|dd
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QMimeTypePrivate
argument_list|(
name|dd
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn void QMimeType::swap(QMimeType&other);     Swaps QMimeType \a other with this QMimeType object.      This operation is very fast and never fails.      The swap() method helps with the implementation of assignment     operators in an exception-safe way. For more information consult     \l {http://en.wikibooks.org/wiki/More_C++_Idioms/Copy-and-swap}     {More C++ Idioms - Copy-and-swap}.  */
end_comment
begin_comment
comment|/*!     \fn QMimeType::~QMimeType();     Destroys the QMimeType object, and releases the d pointer.  */
end_comment
begin_destructor
DECL|function|~QMimeType
name|QMimeType
operator|::
name|~
name|QMimeType
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn bool QMimeType::operator==(const QMimeType&other) const;     Returns true if \a other equals this QMimeType object, otherwise returns false.     The name is the unique identifier for a mimetype, so two mimetypes with     the same name, are equal.  */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QMimeType
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|==
name|other
operator|.
name|d
operator|||
name|d
operator|->
name|name
operator|==
name|other
operator|.
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QMimeType::operator!=(const QMimeType&other) const;     Returns true if \a other does not equal this QMimeType object, otherwise returns false.  */
end_comment
begin_comment
comment|/*!     \fn bool QMimeType::isValid() const;     Returns true if the QMimeType object contains valid data, otherwise returns false.     A valid MIME type has a non-empty name().     The invalid MIME type is the default-constructed QMimeType.  */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QMimeType
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|d
operator|->
name|name
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QMimeType::isDefault() const;     Returns true if this MIME type is the default MIME type which     applies to all files: application/octet-stream.  */
end_comment
begin_function
DECL|function|isDefault
name|bool
name|QMimeType
operator|::
name|isDefault
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
operator|==
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|defaultMimeType
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QMimeType::name() const;     Returns the name of the MIME type.  */
end_comment
begin_function
DECL|function|name
name|QString
name|QMimeType
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
comment|/*!     Returns the description of the MIME type to be displayed on user interfaces.      The system language (QLocale::system().name()) is used to select the appropriate translation.  */
end_comment
begin_function
DECL|function|comment
name|QString
name|QMimeType
operator|::
name|comment
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadMimeTypePrivate
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
name|QStringList
name|languageList
decl_stmt|;
name|languageList
operator|<<
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|name
argument_list|()
expr_stmt|;
name|languageList
operator|<<
name|QLocale
operator|::
name|system
argument_list|()
operator|.
name|uiLanguages
argument_list|()
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QString&language
argument_list|,
argument|languageList
argument_list|)
block|{
specifier|const
name|QString
name|lang
init|=
name|language
operator|==
name|QLatin1String
argument_list|(
literal|"C"
argument_list|)
condition|?
name|QLatin1String
argument_list|(
literal|"en_US"
argument_list|)
else|:
name|language
decl_stmt|;
specifier|const
name|QString
name|comm
init|=
name|d
operator|->
name|localeComments
operator|.
name|value
argument_list|(
name|lang
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|comm
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|comm
return|;
specifier|const
name|int
name|pos
init|=
name|lang
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|pos
operator|!=
operator|-
literal|1
condition|)
block|{
comment|// "pt_BR" not found? try just "pt"
specifier|const
name|QString
name|shortLang
init|=
name|lang
operator|.
name|left
argument_list|(
name|pos
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|commShort
init|=
name|d
operator|->
name|localeComments
operator|.
name|value
argument_list|(
name|shortLang
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|commShort
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|commShort
return|;
block|}
block|}
comment|// Use the mimetype name as fallback
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QMimeType::genericIconName() const;     Returns the file name of a generic icon that represents the MIME type.      This should be used if the icon returned by iconName() cannot be found on     the system. It is used for categories of similar types (like spreadsheets     or archives) that can use a common icon.     The freedesktop.org Icon Naming Specification lists a set of such icon names.      The icon name can be given to QIcon::fromTheme() in order to load the icon.  */
end_comment
begin_function
DECL|function|genericIconName
name|QString
name|QMimeType
operator|::
name|genericIconName
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadGenericIcon
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|genericIconName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// From the spec:
comment|// If the generic icon name is empty (not specified by the mimetype definition)
comment|// then the mimetype is used to generate the generic icon by using the top-level
comment|// media type (e.g.  "video" in "video/ogg") and appending "-x-generic"
comment|// (i.e. "video-x-generic" in the previous example).
name|QString
name|group
init|=
name|name
argument_list|()
decl_stmt|;
specifier|const
name|int
name|slashindex
init|=
name|group
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|slashindex
operator|!=
operator|-
literal|1
condition|)
name|group
operator|=
name|group
operator|.
name|left
argument_list|(
name|slashindex
argument_list|)
expr_stmt|;
return|return
name|group
operator|+
name|QLatin1String
argument_list|(
literal|"-x-generic"
argument_list|)
return|;
block|}
return|return
name|d
operator|->
name|genericIconName
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QMimeType::iconName() const;     Returns the file name of an icon image that represents the MIME type.      The icon name can be given to QIcon::fromTheme() in order to load the icon.  */
end_comment
begin_function
DECL|function|iconName
name|QString
name|QMimeType
operator|::
name|iconName
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadIcon
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|iconName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Make default icon name from the mimetype name
name|d
operator|->
name|iconName
operator|=
name|name
argument_list|()
expr_stmt|;
specifier|const
name|int
name|slashindex
init|=
name|d
operator|->
name|iconName
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|slashindex
operator|!=
operator|-
literal|1
condition|)
name|d
operator|->
name|iconName
index|[
name|slashindex
index|]
operator|=
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
block|}
return|return
name|d
operator|->
name|iconName
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QStringList QMimeType::globPatterns() const;     Returns the list of glob matching patterns.  */
end_comment
begin_function
DECL|function|globPatterns
name|QStringList
name|QMimeType
operator|::
name|globPatterns
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadMimeTypePrivate
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|globPatterns
return|;
block|}
end_function
begin_comment
comment|/*!     A type is a subclass of another type if any instance of the first type is     also an instance of the second. For example, all image/svg+xml files are also     text/xml, text/plain and application/octet-stream files. Subclassing is about     the format, rather than the category of the data (for example, there is no     'generic spreadsheet' class that all spreadsheets inherit from).     Conversely, the parent mimetype of image/svg+xml is text/xml.      A mimetype can have multiple parents. For instance application/x-perl     has two parents: application/x-executable and text/plain. This makes     it possible to both execute perl scripts, and to open them in text editors. */
end_comment
begin_function
DECL|function|parentMimeTypes
name|QStringList
name|QMimeType
operator|::
name|parentMimeTypes
parameter_list|()
specifier|const
block|{
return|return
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|parents
argument_list|(
name|d
operator|->
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|collectParentMimeTypes
specifier|static
name|void
name|collectParentMimeTypes
parameter_list|(
specifier|const
name|QString
modifier|&
name|mime
parameter_list|,
name|QStringList
modifier|&
name|allParents
parameter_list|)
block|{
name|QStringList
name|parents
init|=
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|parents
argument_list|(
name|mime
argument_list|)
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|parent
decl|,
name|parents
control|)
block|{
comment|// I would use QSet, but since order matters I better not
if|if
condition|(
operator|!
name|allParents
operator|.
name|contains
argument_list|(
name|parent
argument_list|)
condition|)
name|allParents
operator|.
name|append
argument_list|(
name|parent
argument_list|)
expr_stmt|;
block|}
comment|// We want a breadth-first search, so that the least-specific parent (octet-stream) is last
comment|// This means iterating twice, unfortunately.
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|parent
decl|,
name|parents
control|)
block|{
name|collectParentMimeTypes
argument_list|(
name|parent
argument_list|,
name|allParents
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Return all the parent mimetypes of this mimetype, direct and indirect.     This includes the parent(s) of its parent(s), etc.      For instance, for image/svg+xml the list would be:     application/xml, text/plain, application/octet-stream.      Note that application/octet-stream is the ultimate parent for all types     of files (but not directories). */
end_comment
begin_function
DECL|function|allAncestors
name|QStringList
name|QMimeType
operator|::
name|allAncestors
parameter_list|()
specifier|const
block|{
name|QStringList
name|allParents
decl_stmt|;
name|collectParentMimeTypes
argument_list|(
name|d
operator|->
name|name
argument_list|,
name|allParents
argument_list|)
expr_stmt|;
return|return
name|allParents
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QStringList QMimeType::suffixes() const;     Returns the known suffixes for the MIME type.  */
end_comment
begin_function
DECL|function|suffixes
name|QStringList
name|QMimeType
operator|::
name|suffixes
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadMimeTypePrivate
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
name|QStringList
name|result
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|pattern
decl|,
name|d
operator|->
name|globPatterns
control|)
block|{
comment|// Not a simple suffix if if looks like: README or *. or *.* or *.JP*G or *.JP?
if|if
condition|(
name|pattern
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"*."
argument_list|)
argument_list|)
operator|&&
name|pattern
operator|.
name|length
argument_list|()
operator|>
literal|2
operator|&&
name|pattern
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'*'
argument_list|)
argument_list|,
literal|2
argument_list|)
operator|<
literal|0
operator|&&
name|pattern
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'?'
argument_list|)
argument_list|,
literal|2
argument_list|)
operator|<
literal|0
condition|)
block|{
specifier|const
name|QString
name|suffix
init|=
name|pattern
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|result
operator|.
name|append
argument_list|(
name|suffix
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QMimeType::preferredSuffix() const;     Returns the preferred suffix for the MIME type.  */
end_comment
begin_function
DECL|function|preferredSuffix
name|QString
name|QMimeType
operator|::
name|preferredSuffix
parameter_list|()
specifier|const
block|{
specifier|const
name|QStringList
name|suffixList
init|=
name|suffixes
argument_list|()
decl_stmt|;
return|return
name|suffixList
operator|.
name|isEmpty
argument_list|()
condition|?
name|QString
argument_list|()
else|:
name|suffixList
operator|.
name|at
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QString QMimeType::filterString() const;     Returns a filter string usable for a file dialog. */
end_comment
begin_function
DECL|function|filterString
name|QString
name|QMimeType
operator|::
name|filterString
parameter_list|()
specifier|const
block|{
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|provider
argument_list|()
operator|->
name|loadMimeTypePrivate
argument_list|(
operator|*
name|d
argument_list|)
expr_stmt|;
name|QString
name|filter
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|globPatterns
operator|.
name|empty
argument_list|()
condition|)
block|{
name|filter
operator|+=
name|comment
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" ("
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|globPatterns
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
name|filter
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|filter
operator|+=
name|d
operator|->
name|globPatterns
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|filter
operator|+=
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
expr_stmt|;
block|}
return|return
name|filter
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QMimeType::inherits(const QString&mimeTypeName) const;     Returns true if this mimetype is \a mimeTypeName,     or inherits \a mimeTypeName (see parentMimeTypes()),     or \a mimeTypeName is an alias for this mimetype.  */
end_comment
begin_function
DECL|function|inherits
name|bool
name|QMimeType
operator|::
name|inherits
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeTypeName
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|name
operator|==
name|mimeTypeName
condition|)
return|return
literal|true
return|;
return|return
name|QMimeDatabasePrivate
operator|::
name|instance
argument_list|()
operator|->
name|inherits
argument_list|(
name|d
operator|->
name|name
argument_list|,
name|mimeTypeName
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
