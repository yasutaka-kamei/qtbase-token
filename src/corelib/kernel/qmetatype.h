begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPE_H
end_ifndef
begin_define
DECL|macro|QMETATYPE_H
define|#
directive|define
name|QMETATYPE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Bool
end_ifdef
begin_error
error|#
directive|error
error|qmetatype.h must be included before any header file that defines Bool
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QMetaType
decl_stmt|{ public:     enum Type
block|{
comment|// these are merged with QVariant
name|Void
operator|=
literal|0
operator|,
name|Bool
operator|=
literal|1
operator|,
name|Int
operator|=
literal|2
operator|,
name|UInt
operator|=
literal|3
operator|,
name|LongLong
operator|=
literal|4
operator|,
name|ULongLong
operator|=
literal|5
operator|,
name|Double
operator|=
literal|6
operator|,
name|QChar
operator|=
literal|7
operator|,
name|QVariantMap
operator|=
literal|8
operator|,
name|QVariantList
operator|=
literal|9
operator|,
name|QString
operator|=
literal|10
operator|,
name|QStringList
operator|=
literal|11
operator|,
name|QByteArray
operator|=
literal|12
operator|,
name|QBitArray
operator|=
literal|13
operator|,
name|QDate
operator|=
literal|14
operator|,
name|QTime
operator|=
literal|15
operator|,
name|QDateTime
operator|=
literal|16
operator|,
name|QUrl
operator|=
literal|17
operator|,
name|QLocale
operator|=
literal|18
operator|,
name|QRect
operator|=
literal|19
operator|,
name|QRectF
operator|=
literal|20
operator|,
name|QSize
operator|=
literal|21
operator|,
name|QSizeF
operator|=
literal|22
operator|,
name|QLine
operator|=
literal|23
operator|,
name|QLineF
operator|=
literal|24
operator|,
name|QPoint
operator|=
literal|25
operator|,
name|QPointF
operator|=
literal|26
operator|,
name|QRegExp
operator|=
literal|27
operator|,
name|QVariantHash
operator|=
literal|28
operator|,
name|QEasingCurve
operator|=
literal|29
operator|,
name|LastCoreType
operator|=
name|QEasingCurve
operator|,
name|FirstGuiType
operator|=
literal|64
comment|/* QFont */
operator|,
name|QFont
operator|=
literal|64
operator|,
name|QPixmap
operator|=
literal|65
operator|,
name|QBrush
operator|=
literal|66
operator|,
name|QColor
operator|=
literal|67
operator|,
name|QPalette
operator|=
literal|68
operator|,
name|QImage
operator|=
literal|69
operator|,
name|QPolygon
operator|=
literal|70
operator|,
name|QRegion
operator|=
literal|71
operator|,
name|QBitmap
operator|=
literal|72
operator|,
name|QCursor
operator|=
literal|73
operator|,
name|QKeySequence
operator|=
literal|74
operator|,
name|QPen
operator|=
literal|75
operator|,
name|QTextLength
operator|=
literal|76
operator|,
name|QTextFormat
operator|=
literal|77
operator|,
name|QMatrix
operator|=
literal|78
operator|,
name|QTransform
operator|=
literal|79
operator|,
name|QMatrix4x4
operator|=
literal|80
operator|,
name|QVector2D
operator|=
literal|81
operator|,
name|QVector3D
operator|=
literal|82
operator|,
name|QVector4D
operator|=
literal|83
operator|,
name|QQuaternion
operator|=
literal|84
operator|,
name|LastGuiType
operator|=
name|QQuaternion
operator|,
name|FirstWidgetsType
operator|=
literal|120
operator|,
comment|/* QIcon */
name|QIcon
operator|=
literal|120
operator|,
name|QSizePolicy
operator|=
literal|121
operator|,
name|LastWidgetsType
operator|=
name|QSizePolicy
operator|,
name|FirstCoreExtType
operator|=
literal|128
comment|/* VoidStar */
operator|,
name|VoidStar
operator|=
literal|128
operator|,
name|Long
operator|=
literal|129
operator|,
name|Short
operator|=
literal|130
operator|,
name|Char
operator|=
literal|131
operator|,
name|ULong
operator|=
literal|132
operator|,
name|UShort
operator|=
literal|133
operator|,
name|UChar
operator|=
literal|134
operator|,
name|Float
operator|=
literal|135
operator|,
name|QObjectStar
operator|=
literal|136
operator|,
name|QWidgetStar
operator|=
literal|137
operator|,
name|QVariant
operator|=
literal|138
operator|,
name|LastCoreExtType
operator|=
name|QVariant
operator|,
comment|// This logic must match the one in qglobal.h
if|#
directive|if
name|defined
argument_list|(
name|QT_COORD_TYPE
argument_list|)
name|QReal
operator|=
literal|0
operator|,
elif|#
directive|elif
name|defined
argument_list|(
name|QT_NO_FPU
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_WINDOWSCE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_ARCH_SYMBIAN
argument_list|)
name|QReal
operator|=
name|Float
operator|,
else|#
directive|else
name|QReal
operator|=
name|Double
operator|,
endif|#
directive|endif
name|User
operator|=
literal|256
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|Constructor
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|SaveOperator
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadOperator
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|void
name|registerStreamOperators
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|SaveOperator
name|saveOp
parameter_list|,
name|LoadOperator
name|loadOp
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|registerStreamOperators
parameter_list|(
name|int
name|type
parameter_list|,
name|SaveOperator
name|saveOp
parameter_list|,
name|LoadOperator
name|loadOp
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|int
name|registerType
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|Destructor
name|destructor
parameter_list|,
name|Constructor
name|constructor
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|registerTypedef
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|,
name|int
name|aliasId
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|int
name|type
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|typeName
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isRegistered
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
modifier|*
name|construct
parameter_list|(
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|destroy
parameter_list|(
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|unregisterType
parameter_list|(
specifier|const
name|char
modifier|*
name|typeName
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_function_decl
specifier|static
name|bool
name|save
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|load
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|int
name|type
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeDeleteHelper
name|void
name|qMetaTypeDeleteHelper
argument_list|(
argument|T *t
argument_list|)
block|{
name|delete
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeConstructHelper
name|void
operator|*
name|qMetaTypeConstructHelper
argument_list|(
argument|const T *t
argument_list|)
block|{
if|if
condition|(
operator|!
name|t
condition|)
return|return
name|new
name|T
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|new
name|T
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
end_return
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeSaveHelper
name|void
name|qMetaTypeSaveHelper
argument_list|(
argument|QDataStream&stream
argument_list|,
argument|const T *t
argument_list|)
block|{
name|stream
operator|<<
operator|*
name|t
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeLoadHelper
name|void
name|qMetaTypeLoadHelper
argument_list|(
argument|QDataStream&stream
argument_list|,
argument|T *t
argument_list|)
block|{
name|stream
operator|>>
operator|*
name|t
block|; }
endif|#
directive|endif
comment|// QT_NO_DATASTREAM
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QMetaTypeId
name|QMetaTypeId
block|{     enum
DECL|enumerator|Defined
block|{
name|Defined
operator|=
literal|0
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|QMetaTypeId2
name|QMetaTypeId2
block|{     enum
DECL|enumerator|Defined
block|{
name|Defined
operator|=
name|QMetaTypeId
operator|<
name|T
operator|>
operator|::
name|Defined
block|}
block|;
DECL|function|qt_metatype_id
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
name|QMetaTypeId
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|qt_metatype_id
unit|};
name|namespace
name|QtPrivate
block|{
name|template
operator|<
name|typename
name|T
operator|,
name|bool
name|Defined
operator|=
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|Defined
operator|>
expr|struct
name|QMetaTypeIdHelper
block|{
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QMetaTypeIdHelper
operator|<
name|T
block|,
name|false
operator|>
block|{
specifier|static
specifier|inline
name|int
name|qt_metatype_id
argument_list|()
block|{
return|return
operator|-
literal|1
return|;
block|}
expr|}
block|; }
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaType
name|int
name|qRegisterMetaType
argument_list|(
argument|const char *typeName
ifndef|#
directive|ifndef
name|qdoc
argument_list|,
argument|T * dummy =
literal|0
endif|#
directive|endif
argument_list|)
block|{
specifier|const
name|int
name|typedefOf
operator|=
name|dummy
operator|?
operator|-
literal|1
operator|:
name|QtPrivate
operator|::
name|QMetaTypeIdHelper
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
block|;
if|if
condition|(
name|typedefOf
operator|!=
operator|-
literal|1
condition|)
return|return
name|QMetaType
operator|::
name|registerTypedef
argument_list|(
name|typeName
argument_list|,
name|typedefOf
argument_list|)
return|;
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|ConstructPtr
function_decl|)
parameter_list|(
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
name|ConstructPtr
name|cptr
operator|=
name|qMetaTypeConstructHelper
operator|<
name|T
operator|>
expr_stmt|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|DeletePtr
function_decl|)
parameter_list|(
name|T
modifier|*
parameter_list|)
function_decl|;
name|DeletePtr
name|dptr
init|=
name|qMetaTypeDeleteHelper
operator|<
name|T
operator|>
decl_stmt|;
return|return
name|QMetaType
operator|::
name|registerType
argument_list|(
name|typeName
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Destructor
operator|>
operator|(
name|dptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|Constructor
operator|>
operator|(
name|cptr
operator|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaTypeStreamOperators
name|void
name|qRegisterMetaTypeStreamOperators
argument_list|(
argument|const char *typeName
ifndef|#
directive|ifndef
name|qdoc
argument_list|,
argument|T *
comment|/* dummy */
argument|=
literal|0
endif|#
directive|endif
argument_list|)
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|SavePtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadPtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|T
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|SavePtr
name|sptr
init|=
name|qMetaTypeSaveHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|LoadPtr
name|lptr
init|=
name|qMetaTypeLoadHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qRegisterMetaType
operator|<
name|T
operator|>
operator|(
name|typeName
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|registerStreamOperators
argument_list|(
name|typeName
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|SaveOperator
operator|>
operator|(
name|sptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|LoadOperator
operator|>
operator|(
name|lptr
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qMetaTypeId
specifier|inline
name|int
name|qMetaTypeId
argument_list|(
ifndef|#
directive|ifndef
name|qdoc
argument|T *
comment|/* dummy */
argument|=
literal|0
endif|#
directive|endif
argument_list|)
block|{
return|return
name|QMetaTypeId2
operator|<
name|T
operator|>
operator|::
name|qt_metatype_id
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaType
specifier|inline
name|int
name|qRegisterMetaType
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|qdoc
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_SUN
argument_list|)
argument|T * dummy =
literal|0
endif|#
directive|endif
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_SUN
return|return
name|qMetaTypeId
argument_list|(
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
literal|0
operator|)
argument_list|)
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|qMetaTypeId
argument_list|(
name|dummy
argument_list|)
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterMetaTypeStreamOperators
specifier|inline
name|int
name|qRegisterMetaTypeStreamOperators
argument_list|()
block|{
typedef|typedef
name|void
function_decl|(
modifier|*
name|SavePtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
specifier|const
name|T
modifier|*
parameter_list|)
function_decl|;
end_expr_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|LoadPtr
function_decl|)
parameter_list|(
name|QDataStream
modifier|&
parameter_list|,
name|T
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
name|SavePtr
name|sptr
init|=
name|qMetaTypeSaveHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|LoadPtr
name|lptr
init|=
name|qMetaTypeLoadHelper
operator|<
name|T
operator|>
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|register
name|int
name|id
init|=
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|registerStreamOperators
argument_list|(
name|id
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|SaveOperator
operator|>
operator|(
name|sptr
operator|)
argument_list|,
name|reinterpret_cast
operator|<
name|QMetaType
operator|::
name|LoadOperator
operator|>
operator|(
name|lptr
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|id
return|;
end_return
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_DECLARE_METATYPE
define|#
directive|define
name|Q_DECLARE_METATYPE
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|QT_BEGIN_NAMESPACE                                                  \     template<>                                                         \     struct QMetaTypeId< TYPE>                                          \     {                                                                   \         enum { Defined = 1 };                                           \         static int qt_metatype_id()                                     \             {                                                           \                 static QBasicAtomicInt metatype_id = Q_BASIC_ATOMIC_INITIALIZER(0); \                 if (!metatype_id)                                       \                     metatype_id = qRegisterMetaType< TYPE>(#TYPE,      \                                reinterpret_cast< TYPE *>(quintptr(-1))); \                 return metatype_id;                                     \             }                                                           \     };                                                                  \     QT_END_NAMESPACE
end_define
begin_define
DECL|macro|Q_DECLARE_BUILTIN_METATYPE
define|#
directive|define
name|Q_DECLARE_BUILTIN_METATYPE
parameter_list|(
name|TYPE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|QT_BEGIN_NAMESPACE \     template<> struct QMetaTypeId2<TYPE> \     { \         enum { Defined = 1, MetaType = QMetaType::NAME }; \         static inline int qt_metatype_id() { return QMetaType::NAME; } \     }; \     QT_END_NAMESPACE
end_define
begin_expr_stmt
unit|class
DECL|variable|QString
name|QString
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QChar
name|class
name|QChar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBitArray
name|class
name|QBitArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDate
name|class
name|QDate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTime
name|class
name|QTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDateTime
name|class
name|QDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLocale
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRectF
name|class
name|QRectF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSizeF
name|class
name|QSizeF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLine
name|class
name|QLine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineF
name|class
name|QLineF
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPointF
name|class
name|QPointF
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_decl_stmt
DECL|variable|QRegExp
name|class
name|QRegExp
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QEasingCurve
name|class
name|QEasingCurve
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
DECL|variable|QColorGroup
name|class
name|QColorGroup
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBrush
name|class
name|QBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygon
name|class
name|QPolygon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBitmap
name|class
name|QBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCursor
name|class
name|QCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSizePolicy
name|class
name|QSizePolicy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeySequence
name|class
name|QKeySequence
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPen
name|class
name|QPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextLength
name|class
name|QTextLength
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTransform
name|class
name|QTransform
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix4x4
name|class
name|QMatrix4x4
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVector2D
name|class
name|QVector2D
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVector3D
name|class
name|QVector3D
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVector4D
name|class
name|QVector4D
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQuaternion
name|class
name|QQuaternion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|int
argument_list|,
name|Int
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|uint
argument_list|,
name|UInt
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|bool
argument_list|,
name|Bool
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|double
argument_list|,
name|Double
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QByteArray
argument_list|,
name|QByteArray
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QChar
argument_list|,
name|QChar
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|long
argument_list|,
name|Long
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|short
argument_list|,
name|Short
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|char
argument_list|,
name|Char
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|signed
name|char
argument_list|,
name|Char
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|ulong
argument_list|,
name|ULong
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|ushort
argument_list|,
name|UShort
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|uchar
argument_list|,
name|UChar
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|float
argument_list|,
name|Float
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QObject
operator|*
argument_list|,
name|QObjectStar
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QWidget
operator|*
argument_list|,
name|QWidgetStar
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|void
operator|*
argument_list|,
name|VoidStar
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|qlonglong
argument_list|,
name|LongLong
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|qulonglong
argument_list|,
name|ULongLong
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QStringList
argument_list|,
name|QStringList
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QBitArray
argument_list|,
name|QBitArray
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QDate
argument_list|,
name|QDate
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QTime
argument_list|,
name|QTime
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QDateTime
argument_list|,
name|QDateTime
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QUrl
argument_list|,
name|QUrl
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QLocale
argument_list|,
name|QLocale
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QRect
argument_list|,
name|QRect
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QRectF
argument_list|,
name|QRectF
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QSize
argument_list|,
name|QSize
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QSizeF
argument_list|,
name|QSizeF
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QLine
argument_list|,
name|QLine
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QLineF
argument_list|,
name|QLineF
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPoint
argument_list|,
name|QPoint
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPointF
argument_list|,
name|QPointF
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QRegExp
argument_list|,
name|QRegExp
argument_list|)
endif|#
directive|endif
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QEasingCurve
argument_list|,
name|QEasingCurve
argument_list|)
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QColorGroup
argument_list|,
name|QColorGroup
argument_list|)
endif|#
directive|endif
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QFont
argument_list|,
name|QFont
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPixmap
argument_list|,
name|QPixmap
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QBrush
argument_list|,
name|QBrush
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QColor
argument_list|,
name|QColor
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPalette
argument_list|,
name|QPalette
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QIcon
argument_list|,
name|QIcon
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QImage
argument_list|,
name|QImage
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPolygon
argument_list|,
name|QPolygon
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QRegion
argument_list|,
name|QRegion
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QBitmap
argument_list|,
name|QBitmap
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QCursor
argument_list|,
name|QCursor
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QSizePolicy
argument_list|,
name|QSizePolicy
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QKeySequence
argument_list|,
name|QKeySequence
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QPen
argument_list|,
name|QPen
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QTextLength
argument_list|,
name|QTextLength
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QTextFormat
argument_list|,
name|QTextFormat
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QMatrix
argument_list|,
name|QMatrix
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QTransform
argument_list|,
name|QTransform
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QMatrix4x4
argument_list|,
name|QMatrix4x4
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QVector2D
argument_list|,
name|QVector2D
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QVector3D
argument_list|,
name|QVector3D
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QVector4D
argument_list|,
name|QVector4D
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QQuaternion
argument_list|,
name|QQuaternion
argument_list|)
name|Q_DECLARE_BUILTIN_METATYPE
argument_list|(
name|QVariant
argument_list|,
name|QVariant
argument_list|)
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPE_H
end_comment
end_unit
