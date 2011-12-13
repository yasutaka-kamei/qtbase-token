begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qicon.h"
end_include
begin_include
include|#
directive|include
file|"qsizepolicy.h"
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
begin_function
name|QT_BEGIN_NAMESPACE
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
switch|switch
condition|(
name|x
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ICON
case|case
name|QVariant
operator|::
name|Icon
case|:
name|v_construct
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|x
argument_list|,
name|copy
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
name|v_construct
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|x
argument_list|,
name|copy
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return;
block|}
name|x
operator|->
name|is_null
operator|=
operator|!
name|copy
expr_stmt|;
block|}
end_function
begin_function
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
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ICON
case|case
name|QVariant
operator|::
name|Icon
case|:
name|v_clear
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
name|v_clear
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|d
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|type
operator|=
name|QVariant
operator|::
name|Invalid
expr_stmt|;
name|d
operator|->
name|is_null
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|is_shared
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
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
switch|switch
condition|(
name|d
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ICON
case|case
name|QVariant
operator|::
name|Icon
case|:
return|return
name|v_cast
argument_list|<
name|QIcon
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|isNull
argument_list|()
return|;
endif|#
directive|endif
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
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
name|Q_ASSERT
argument_list|(
name|a
operator|->
name|type
operator|==
name|b
operator|->
name|type
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|a
operator|->
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_ICON
case|case
name|QVariant
operator|::
name|Icon
case|:
return|return
literal|false
return|;
endif|#
directive|endif
case|case
name|QVariant
operator|::
name|SizePolicy
case|:
return|return
operator|*
name|v_cast
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|a
argument_list|)
operator|==
operator|*
name|v_cast
argument_list|<
name|QSizePolicy
argument_list|>
argument_list|(
name|b
argument_list|)
return|;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|widgets_handler
specifier|static
specifier|const
name|QVariant
operator|::
name|Handler
name|widgets_handler
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
literal|0
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
operator|&&
operator|!
name|defined
argument_list|(
name|Q_BROKEN_DEBUG_STREAM
argument_list|)
literal|0
else|#
directive|else
literal|0
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|Q_CORE_EXPORT
specifier|const
name|QMetaTypeInterface
modifier|*
name|qMetaTypeWidgetsHelper
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
define|#
directive|define
name|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
parameter_list|(
name|MetaTypeName
parameter_list|,
name|MetaTypeId
parameter_list|,
name|RealName
parameter_list|)
define|\
value|QT_METATYPE_INTERFACE_INIT(RealName),
end_define
begin_decl_stmt
DECL|variable|qVariantWidgetsHelper
specifier|static
specifier|const
name|QMetaTypeInterface
name|qVariantWidgetsHelper
index|[]
init|=
block|{
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
undef|#
directive|undef
name|QT_IMPL_METATYPEINTERFACE_WIDGETS_TYPES
end_undef
begin_decl_stmt
specifier|extern
name|Q_GUI_EXPORT
specifier|const
name|QVariant
operator|::
name|Handler
modifier|*
name|qt_widgets_variant_handler
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qRegisterWidgetsVariant
name|void
name|qRegisterWidgetsVariant
parameter_list|()
block|{
name|qt_widgets_variant_handler
operator|=
operator|&
name|widgets_handler
expr_stmt|;
name|qMetaTypeWidgetsHelper
operator|=
name|qVariantWidgetsHelper
expr_stmt|;
block|}
end_function
begin_macro
name|Q_CONSTRUCTOR_FUNCTION
argument_list|(
argument|qRegisterWidgetsVariant
argument_list|)
end_macro
begin_function
DECL|function|qUnregisterWidgetsVariant
name|void
name|qUnregisterWidgetsVariant
parameter_list|()
block|{
name|qt_widgets_variant_handler
operator|=
literal|0
expr_stmt|;
name|qMetaTypeWidgetsHelper
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DESTRUCTOR_FUNCTION
argument_list|(
argument|qUnregisterWidgetsVariant
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
