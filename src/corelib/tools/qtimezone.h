begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 John Layt<jlayt@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMEZONE_H
end_ifndef
begin_define
DECL|macro|QTIMEZONE_H
define|#
directive|define
name|QTIMEZONE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTimeZonePrivate
name|class
name|QTimeZonePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTimeZone
block|{
name|public
label|:
enum|enum
name|TimeType
block|{
name|StandardTime
init|=
literal|0
block|,
name|DaylightTime
init|=
literal|1
block|,
name|GenericTime
init|=
literal|2
block|}
enum|;
enum|enum
name|NameType
block|{
name|DefaultName
init|=
literal|0
block|,
name|LongName
init|=
literal|1
block|,
name|ShortName
init|=
literal|2
block|,
name|OffsetName
init|=
literal|3
block|}
enum|;
struct|struct
name|OffsetData
block|{
name|QString
name|abbreviation
decl_stmt|;
name|QDateTime
name|atUtc
decl_stmt|;
name|int
name|offsetFromUtc
decl_stmt|;
name|int
name|standardTimeOffset
decl_stmt|;
name|int
name|daylightTimeOffset
decl_stmt|;
block|}
struct|;
typedef|typedef
name|QVector
operator|<
name|OffsetData
operator|>
name|OffsetDataList
expr_stmt|;
name|QTimeZone
argument_list|()
expr_stmt|;
name|explicit
name|QTimeZone
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|olsenId
parameter_list|)
function_decl|;
name|QTimeZone
argument_list|(
argument|int offsetSeconds
argument_list|)
empty_stmt|;
name|QTimeZone
argument_list|(
argument|const QByteArray&zoneId
argument_list|,
argument|int offsetSeconds
argument_list|,
argument|const QString&name
argument_list|,
argument|const QString&abbreviation
argument_list|,
argument|QLocale::Country country = QLocale::AnyCountry
argument_list|,
argument|const QString&comment = QString()
argument_list|)
empty_stmt|;
name|QTimeZone
argument_list|(
specifier|const
name|QTimeZone
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QTimeZone
argument_list|()
expr_stmt|;
name|QTimeZone
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTimeZone
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QTimeZone
modifier|&
name|operator
init|=
operator|(
name|QTimeZone
operator|&&
name|other
operator|)
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QTimeZone
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTimeZone
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTimeZone
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|id
argument_list|()
specifier|const
expr_stmt|;
name|QLocale
operator|::
name|Country
name|country
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|comment
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|displayName
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
operator|=
name|QTimeZone
operator|::
name|DefaultName
argument_list|,
specifier|const
name|QLocale
operator|&
name|locale
operator|=
name|QLocale
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|displayName
argument_list|(
name|QTimeZone
operator|::
name|TimeType
name|timeType
argument_list|,
name|QTimeZone
operator|::
name|NameType
name|nameType
operator|=
name|QTimeZone
operator|::
name|DefaultName
argument_list|,
specifier|const
name|QLocale
operator|&
name|locale
operator|=
name|QLocale
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|abbreviation
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|)
decl|const
decl_stmt|;
name|int
name|offsetFromUtc
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|)
decl|const
decl_stmt|;
name|int
name|standardTimeOffset
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|)
decl|const
decl_stmt|;
name|int
name|daylightTimeOffset
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasDaylightTime
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDaylightTime
argument_list|(
specifier|const
name|QDateTime
operator|&
name|atDateTime
argument_list|)
decl|const
decl_stmt|;
name|OffsetData
name|offsetData
argument_list|(
specifier|const
name|QDateTime
operator|&
name|forDateTime
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasTransitions
argument_list|()
specifier|const
expr_stmt|;
name|OffsetData
name|nextTransition
argument_list|(
specifier|const
name|QDateTime
operator|&
name|afterDateTime
argument_list|)
decl|const
decl_stmt|;
name|OffsetData
name|previousTransition
argument_list|(
specifier|const
name|QDateTime
operator|&
name|beforeDateTime
argument_list|)
decl|const
decl_stmt|;
name|OffsetDataList
name|transitions
argument_list|(
specifier|const
name|QDateTime
operator|&
name|fromDateTime
argument_list|,
specifier|const
name|QDateTime
operator|&
name|toDateTime
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QByteArray
name|systemTimeZoneId
parameter_list|()
function_decl|;
specifier|static
name|bool
name|isTimeZoneIdAvailable
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|olsenId
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|()
expr_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|QLocale::Country country
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|availableTimeZoneIds
argument_list|(
argument|int offsetSeconds
argument_list|)
expr_stmt|;
specifier|static
name|QByteArray
name|olsenIdToWindowsId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|olsenId
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|windowsIdToDefaultOlsenId
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|windowsId
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|windowsIdToDefaultOlsenId
argument_list|(
specifier|const
name|QByteArray
operator|&
name|windowsId
argument_list|,
name|QLocale
operator|::
name|Country
name|country
argument_list|)
decl_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|windowsIdToOlsenIds
argument_list|(
specifier|const
name|QByteArray
operator|&
name|windowsId
argument_list|)
expr_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|windowsIdToOlsenIds
argument_list|(
argument|const QByteArray&windowsId
argument_list|,
argument|QLocale::Country country
argument_list|)
expr_stmt|;
name|private
label|:
name|QTimeZone
argument_list|(
name|QTimeZonePrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QTimeZone
operator|&
name|tz
operator|)
expr_stmt|;
endif|#
directive|endif
name|friend
name|class
name|QTimeZonePrivate
decl_stmt|;
name|friend
name|class
name|QDateTime
decl_stmt|;
name|friend
name|class
name|QDateTimePrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QTimeZonePrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTimeZone
operator|::
name|OffsetData
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QTimeZone
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QTimeZone
operator|&
name|tz
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QTimeZone
operator|&
name|tz
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QTimeZone
operator|&
name|tz
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTIMEZONE_H
end_comment
end_unit
