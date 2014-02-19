begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Gui types
end_comment
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qbrush.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_include
include|#
directive|include
file|"qcursor.h"
end_include
begin_include
include|#
directive|include
file|"qfont.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qkeysequence.h"
end_include
begin_include
include|#
directive|include
file|"qtransform.h"
end_include
begin_include
include|#
directive|include
file|"qmatrix.h"
end_include
begin_include
include|#
directive|include
file|"qpalette.h"
end_include
begin_include
include|#
directive|include
file|"qpen.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qpolygon.h"
end_include
begin_include
include|#
directive|include
file|"qregion.h"
end_include
begin_include
include|#
directive|include
file|"qtextformat.h"
end_include
begin_include
include|#
directive|include
file|"qmatrix4x4.h"
end_include
begin_include
include|#
directive|include
file|"qvector2d.h"
end_include
begin_include
include|#
directive|include
file|"qvector3d.h"
end_include
begin_include
include|#
directive|include
file|"qvector4d.h"
end_include
begin_include
include|#
directive|include
file|"qquaternion.h"
end_include
begin_include
include|#
directive|include
file|"qicon.h"
end_include
begin_comment
comment|// Core types
end_comment
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qbitarray.h"
end_include
begin_include
include|#
directive|include
file|"qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"qdatastream.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qmap.h"
end_include
begin_include
include|#
directive|include
file|"qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"qeasingcurve.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_include
include|#
directive|include
file|"qlocale.h"
end_include
begin_include
include|#
directive|include
file|"quuid.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GEOM_VARIANT
end_ifndef
begin_include
include|#
directive|include
file|"qsize.h"
end_include
begin_include
include|#
directive|include
file|"qpoint.h"
end_include
begin_include
include|#
directive|include
file|"qrect.h"
end_include
begin_include
include|#
directive|include
file|"qline.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_include
include|#
directive|include
file|"private/qvariant_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qmetatype_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_CORE_EXPORT
specifier|const
name|QVariant
operator|::
name|Handler
modifier|*
name|qcoreVariantHandler
parameter_list|()
function_decl|;
end_function_decl
begin_namespace
namespace|namespace
block|{
DECL|struct|GuiTypesFilter
struct|struct
name|GuiTypesFilter
block|{
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
struct|struct
DECL|struct|Acceptor
name|Acceptor
block|{
DECL|member|IsAccepted
specifier|static
specifier|const
name|bool
name|IsAccepted
init|=
name|QModulesPrivate
operator|::
name|QTypeModuleInfo
argument_list|<
name|T
argument_list|>
operator|::
name|IsGui
operator|&&
name|QtMetaTypePrivate
operator|::
name|TypeDefinition
argument_list|<
name|T
argument_list|>
operator|::
name|IsAvailable
decl_stmt|;
block|}
struct|;
block|}
struct|;
DECL|function|construct
specifier|static
name|void
name|construct
parameter_list|(
name|QVariant
operator|::
name|Private
modifier|*
name|x
parameter_list|,
specifier|const
name|void
modifier|*
name|copy
parameter_list|)
block|{
specifier|const
name|int
name|type
init|=
name|x
operator|->
name|type
decl_stmt|;
name|QVariantConstructor
argument_list|<
name|GuiTypesFilter
argument_list|>
name|constructor
argument_list|(
name|x
argument_list|,
name|copy
argument_list|)
decl_stmt|;
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|<
name|void
argument_list|>
argument_list|(
name|constructor
argument_list|,
name|type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
DECL|function|clear
specifier|static
name|void
name|clear
parameter_list|(
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|)
block|{
name|QVariantDestructor
argument_list|<
name|GuiTypesFilter
argument_list|>
name|destructor
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|<
name|void
argument_list|>
argument_list|(
name|destructor
argument_list|,
name|d
operator|->
name|type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
comment|// This class is a hack that customizes access to QPolygon and QPolygonF
template|template
parameter_list|<
name|class
name|Filter
parameter_list|>
class|class
DECL|class|QGuiVariantIsNull
name|QGuiVariantIsNull
super|:
specifier|public
name|QVariantIsNull
argument_list|<
name|Filter
argument_list|>
block|{
DECL|typedef|Base
typedef|typedef
name|QVariantIsNull
argument_list|<
name|Filter
argument_list|>
name|Base
typedef|;
public|public:
DECL|function|QGuiVariantIsNull
name|QGuiVariantIsNull
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|)
member_init_list|:
name|QVariantIsNull
argument_list|<
name|Filter
argument_list|>
argument_list|(
name|d
argument_list|)
block|{}
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|T
modifier|*
name|p
parameter_list|)
block|{
return|return
name|Base
operator|::
name|delegate
argument_list|(
name|p
argument_list|)
return|;
block|}
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QPolygon
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QPolygon
argument_list|>
argument_list|(
name|Base
operator|::
name|m_d
argument_list|)
operator|->
name|isEmpty
argument_list|()
return|;
block|}
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QPolygonF
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QPolygonF
argument_list|>
argument_list|(
name|Base
operator|::
name|m_d
argument_list|)
operator|->
name|isEmpty
argument_list|()
return|;
block|}
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|Base
operator|::
name|delegate
argument_list|(
name|p
argument_list|)
return|;
block|}
block|}
class|;
DECL|function|isNull
specifier|static
name|bool
name|isNull
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|)
block|{
name|QGuiVariantIsNull
argument_list|<
name|GuiTypesFilter
argument_list|>
name|isNull
argument_list|(
name|d
argument_list|)
decl_stmt|;
return|return
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|<
name|bool
argument_list|>
argument_list|(
name|isNull
argument_list|,
name|d
operator|->
name|type
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|// This class is a hack that customizes access to QPixmap, QBitmap, QCursor and QIcon
template|template
parameter_list|<
name|class
name|Filter
parameter_list|>
class|class
DECL|class|QGuiVariantComparator
name|QGuiVariantComparator
super|:
specifier|public
name|QVariantComparator
argument_list|<
name|Filter
argument_list|>
block|{
DECL|typedef|Base
typedef|typedef
name|QVariantComparator
argument_list|<
name|Filter
argument_list|>
name|Base
typedef|;
public|public:
DECL|function|QGuiVariantComparator
name|QGuiVariantComparator
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|a
parameter_list|,
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|b
parameter_list|)
member_init_list|:
name|QVariantComparator
argument_list|<
name|Filter
argument_list|>
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
block|{}
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|T
modifier|*
name|p
parameter_list|)
block|{
return|return
name|Base
operator|::
name|delegate
argument_list|(
name|p
argument_list|)
return|;
block|}
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QPixmap
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|Base
operator|::
name|m_a
argument_list|)
operator|->
name|cacheKey
argument_list|()
operator|==
name|v_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|Base
operator|::
name|m_b
argument_list|)
operator|->
name|cacheKey
argument_list|()
return|;
block|}
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QBitmap
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QBitmap
argument_list|>
argument_list|(
name|Base
operator|::
name|m_a
argument_list|)
operator|->
name|cacheKey
argument_list|()
operator|==
name|v_cast
argument_list|<
name|QBitmap
argument_list|>
argument_list|(
name|Base
operator|::
name|m_b
argument_list|)
operator|->
name|cacheKey
argument_list|()
return|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QCursor
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QCursor
argument_list|>
argument_list|(
name|Base
operator|::
name|m_a
argument_list|)
operator|->
name|shape
argument_list|()
operator|==
name|v_cast
argument_list|<
name|QCursor
argument_list|>
argument_list|(
name|Base
operator|::
name|m_b
argument_list|)
operator|->
name|shape
argument_list|()
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_ICON
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|QIcon
modifier|*
parameter_list|)
block|{
return|return
name|v_cast
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|Base
operator|::
name|m_a
argument_list|)
operator|->
name|cacheKey
argument_list|()
operator|==
name|v_cast
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|Base
operator|::
name|m_b
argument_list|)
operator|->
name|cacheKey
argument_list|()
return|;
block|}
endif|#
directive|endif
DECL|function|delegate
name|bool
name|delegate
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
name|Base
operator|::
name|delegate
argument_list|(
name|p
argument_list|)
return|;
block|}
block|}
class|;
DECL|function|compare
specifier|static
name|bool
name|compare
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|a
parameter_list|,
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|b
parameter_list|)
block|{
name|QGuiVariantComparator
argument_list|<
name|GuiTypesFilter
argument_list|>
name|comparator
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
return|return
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|<
name|bool
argument_list|>
argument_list|(
name|comparator
argument_list|,
name|a
operator|->
name|type
argument_list|,
literal|0
argument_list|)
return|;
block|}
DECL|function|convert
specifier|static
name|bool
name|convert
parameter_list|(
specifier|const
name|QVariant
operator|::
name|Private
modifier|*
name|d
parameter_list|,
name|int
name|t
parameter_list|,
name|void
modifier|*
name|result
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
block|{
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|QVariant
operator|::
name|ByteArray
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Color
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|v_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|name
argument_list|()
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QVariant
operator|::
name|String
case|:
block|{
name|QString
modifier|*
name|str
init|=
cast|static_cast
argument_list|<
name|QString
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
case|case
name|QVariant
operator|::
name|KeySequence
case|:
operator|*
name|str
operator|=
operator|(
operator|*
name|v_cast
argument_list|<
name|QKeySequence
argument_list|>
argument_list|(
name|d
argument_list|)
operator|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|Font
case|:
operator|*
name|str
operator|=
name|v_cast
argument_list|<
name|QFont
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|toString
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QVariant
operator|::
name|Color
case|:
operator|*
name|str
operator|=
name|v_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|name
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
default|default:
break|break;
block|}
break|break;
block|}
case|case
name|QVariant
operator|::
name|Pixmap
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Image
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Bitmap
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
operator|*
name|v_cast
argument_list|<
name|QBitmap
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Brush
condition|)
block|{
if|if
condition|(
name|v_cast
argument_list|<
name|QBrush
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|TexturePattern
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|v_cast
argument_list|<
name|QBrush
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|texture
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
break|break;
case|case
name|QVariant
operator|::
name|Image
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Pixmap
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QImage
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|v_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|toImage
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Bitmap
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QImage
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|v_cast
argument_list|<
name|QBitmap
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|toImage
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QVariant
operator|::
name|Bitmap
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Pixmap
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QBitmap
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
operator|*
name|v_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Image
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QBitmap
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|QBitmap
operator|::
name|fromImage
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
case|case
name|QVariant
operator|::
name|Int
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|KeySequence
condition|)
block|{
specifier|const
name|QKeySequence
modifier|&
name|seq
init|=
operator|*
name|v_cast
argument_list|<
name|QKeySequence
argument_list|>
argument_list|(
name|d
argument_list|)
decl_stmt|;
operator|*
cast|static_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|seq
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
name|seq
index|[
literal|0
index|]
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|Font
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|String
condition|)
block|{
name|QFont
modifier|*
name|f
init|=
cast|static_cast
argument_list|<
name|QFont
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
decl_stmt|;
name|f
operator|->
name|fromString
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
case|case
name|QVariant
operator|::
name|Color
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|String
condition|)
block|{
cast|static_cast
argument_list|<
name|QColor
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|->
name|setNamedColor
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
cast|static_cast
argument_list|<
name|QColor
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|->
name|isValid
argument_list|()
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|ByteArray
condition|)
block|{
cast|static_cast
argument_list|<
name|QColor
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|->
name|setNamedColor
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Brush
condition|)
block|{
if|if
condition|(
name|v_cast
argument_list|<
name|QBrush
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|SolidPattern
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QColor
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|v_cast
argument_list|<
name|QBrush
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|color
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
break|break;
case|case
name|QVariant
operator|::
name|Brush
case|:
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Color
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QBrush
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|QBrush
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|d
operator|->
name|type
operator|==
name|QVariant
operator|::
name|Pixmap
condition|)
block|{
operator|*
cast|static_cast
argument_list|<
name|QBrush
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
operator|=
name|QBrush
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
case|case
name|QVariant
operator|::
name|KeySequence
case|:
block|{
name|QKeySequence
modifier|*
name|seq
init|=
cast|static_cast
argument_list|<
name|QKeySequence
operator|*
argument_list|>
argument_list|(
name|result
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
case|case
name|QVariant
operator|::
name|String
case|:
operator|*
name|seq
operator|=
name|QKeySequence
argument_list|(
operator|*
name|v_cast
argument_list|<
name|QString
argument_list|>
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
case|case
name|QVariant
operator|::
name|Int
case|:
operator|*
name|seq
operator|=
name|QKeySequence
argument_list|(
name|d
operator|->
name|data
operator|.
name|i
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
default|default:
break|break;
block|}
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_ICON
case|case
name|QVariant
operator|::
name|Icon
case|:
block|{
if|if
condition|(
name|ok
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
literal|false
return|;
block|}
endif|#
directive|endif
default|default:
break|break;
block|}
return|return
name|qcoreVariantHandler
argument_list|()
operator|->
name|convert
argument_list|(
name|d
argument_list|,
name|t
argument_list|,
name|result
argument_list|,
name|ok
argument_list|)
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
DECL|function|streamDebug
specifier|static
name|void
name|streamDebug
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|v
parameter_list|)
block|{
name|QVariant
operator|::
name|Private
modifier|*
name|d
init|=
cast|const_cast
argument_list|<
name|QVariant
operator|::
name|Private
operator|*
argument_list|>
argument_list|(
operator|&
name|v
operator|.
name|data_ptr
argument_list|()
argument_list|)
decl_stmt|;
name|QVariantDebugStream
argument_list|<
name|GuiTypesFilter
argument_list|>
name|stream
argument_list|(
name|dbg
argument_list|,
name|d
argument_list|)
decl_stmt|;
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|<
name|void
argument_list|>
argument_list|(
name|stream
argument_list|,
name|d
operator|->
name|type
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
DECL|member|qt_gui_variant_handler
specifier|const
name|QVariant
operator|::
name|Handler
name|qt_gui_variant_handler
init|=
block|{
name|construct
block|,
name|clear
block|,
name|isNull
block|,
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
literal|0
block|,
literal|0
block|,
endif|#
directive|endif
name|compare
block|,
name|convert
block|,
literal|0
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
name|streamDebug
else|#
directive|else
literal|0
endif|#
directive|endif
block|}
decl_stmt|;
DECL|macro|QT_IMPL_METATYPEINTERFACE_GUI_TYPES
define|#
directive|define
name|QT_IMPL_METATYPEINTERFACE_GUI_TYPES
parameter_list|(
name|MetaTypeName
parameter_list|,
name|MetaTypeId
parameter_list|,
name|RealName
parameter_list|)
define|\
value|QT_METATYPE_INTERFACE_INIT(RealName),
DECL|member|qVariantGuiHelper
specifier|static
specifier|const
name|QMetaTypeInterface
name|qVariantGuiHelper
index|[]
init|=
block|{
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|QT_IMPL_METATYPEINTERFACE_GUI_TYPES
argument_list|)
block|}
decl_stmt|;
DECL|macro|QT_IMPL_METATYPEINTERFACE_GUI_TYPES
undef|#
directive|undef
name|QT_IMPL_METATYPEINTERFACE_GUI_TYPES
block|}
end_namespace
begin_comment
comment|// namespace used to hide QVariant handler
end_comment
begin_decl_stmt
specifier|extern
name|Q_CORE_EXPORT
specifier|const
name|QMetaTypeInterface
modifier|*
name|qMetaTypeGuiHelper
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qRegisterGuiVariant
name|void
name|qRegisterGuiVariant
parameter_list|()
block|{
name|QVariantPrivate
operator|::
name|registerHandler
argument_list|(
name|QModulesPrivate
operator|::
name|Gui
argument_list|,
operator|&
name|qt_gui_variant_handler
argument_list|)
expr_stmt|;
name|qMetaTypeGuiHelper
operator|=
name|qVariantGuiHelper
expr_stmt|;
block|}
end_function
begin_macro
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
argument|qRegisterGuiVariant
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
