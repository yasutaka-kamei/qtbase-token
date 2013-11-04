begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVARIANT_P_H
end_ifndef
begin_define
DECL|macro|QVARIANT_P_H
define|#
directive|define
name|QVARIANT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qmetatype_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qmetatypeswitcher_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QVariantIntegrator
block|{
specifier|static
specifier|const
name|bool
name|CanUseInternalSpace
operator|=
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
operator|&&
operator|(
operator|(
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
operator|)
operator|||
name|Q_IS_ENUM
argument_list|(
name|T
argument_list|)
operator|)
block|; }
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
name|QVariantIntegrator
operator|<
name|double
operator|>
operator|::
name|CanUseInternalSpace
argument_list|)
expr_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
argument|QVariantIntegrator<long int>::CanUseInternalSpace
argument_list|)
empty_stmt|;
name|Q_STATIC_ASSERT
argument_list|(
name|QVariantIntegrator
operator|<
name|qulonglong
operator|>
operator|::
name|CanUseInternalSpace
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_SUN
end_ifdef
begin_comment
comment|// Sun CC picks the wrong overload, so introduce awful hack
end_comment
begin_comment
comment|// takes a type, returns the internal void* pointer cast
end_comment
begin_comment
comment|// to a pointer of the input type
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|v_cast
specifier|inline
name|T
operator|*
name|v_cast
argument_list|(
argument|const QVariant::Private *nd
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
name|QVariant
operator|::
name|Private
operator|*
name|d
operator|=
name|const_cast
operator|<
name|QVariant
operator|::
name|Private
operator|*
operator|>
operator|(
name|nd
operator|)
block|;
return|return
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
condition|?
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
else|:
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// every other compiler in this world
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|v_cast
specifier|inline
specifier|const
name|T
operator|*
name|v_cast
argument_list|(
argument|const QVariant::Private *d
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
return|return
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
operator|?
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
operator|:
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|v_cast
specifier|inline
name|T
operator|*
name|v_cast
argument_list|(
argument|QVariant::Private *d
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
return|return
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
operator|?
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|->
name|ptr
operator|)
operator|:
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|d
operator|->
name|data
operator|.
name|c
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//a simple template that avoids to allocate 2 memory chunks when creating a QVariant
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QVariantPrivateSharedEx
operator|:
name|public
name|QVariant
operator|::
name|PrivateShared
block|{
name|public
operator|:
name|QVariantPrivateSharedEx
argument_list|()
operator|:
name|QVariant
operator|::
name|PrivateShared
argument_list|(
argument|&m_t
argument_list|)
block|{ }
name|QVariantPrivateSharedEx
argument_list|(
specifier|const
name|T
operator|&
name|t
argument_list|)
operator|:
name|QVariant
operator|::
name|PrivateShared
argument_list|(
operator|&
name|m_t
argument_list|)
block|,
name|m_t
argument_list|(
argument|t
argument_list|)
block|{ }
name|private
operator|:
name|T
name|m_t
block|; }
expr_stmt|;
end_expr_stmt
begin_comment
comment|// constructs a new variant if copy is 0, otherwise copy-constructs
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|v_construct
specifier|inline
name|void
name|v_construct
argument_list|(
argument|QVariant::Private *x
argument_list|,
argument|const void *copy
argument_list|,
argument|T * =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
condition|)
block|{
name|x
operator|->
name|data
operator|.
name|shared
operator|=
name|copy
condition|?
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|copy
operator|)
operator|)
else|:
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
expr_stmt|;
name|x
operator|->
name|is_shared
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
if|if
condition|(
name|copy
condition|)
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
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
name|copy
operator|)
argument_list|)
expr_stmt|;
else|else
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
name|T
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|>
DECL|function|v_construct
specifier|inline
name|void
name|v_construct
argument_list|(
argument|QVariant::Private *x
argument_list|,
argument|const T&t
argument_list|)
block|{
if|if
condition|(
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
condition|)
block|{
name|x
operator|->
name|data
operator|.
name|shared
operator|=
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|(
name|t
operator|)
expr_stmt|;
name|x
operator|->
name|is_shared
operator|=
name|true
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|new
argument_list|(
argument|&x->data.ptr
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_else
begin_comment
unit|}
comment|// deletes the internal structures
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|v_clear
specifier|inline
name|void
name|v_clear
argument_list|(
argument|QVariant::Private *d
argument_list|,
argument|T* =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
condition|)
block|{
comment|//now we need to cast
comment|//because QVariant::PrivateShared doesn't have a virtual destructor
name|delete
name|static_cast
operator|<
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|d
operator|->
name|data
operator|.
name|shared
operator|)
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|v_cast
operator|<
name|T
operator|>
operator|(
name|d
operator|)
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  template
operator|<
name|class
name|Filter
operator|>
name|class
name|QVariantComparator
block|{
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|IsAcceptedType
operator|=
name|Filter
operator|::
name|template
name|Acceptor
operator|<
name|T
operator|>
operator|::
name|IsAccepted
operator|>
expr|struct
name|FilteredComparator
block|{
specifier|static
name|bool
name|compare
argument_list|(
argument|const QVariant::Private *a
argument_list|,
argument|const QVariant::Private *b
argument_list|)
block|{
return|return
operator|*
name|v_cast
operator|<
name|T
operator|>
operator|(
name|a
operator|)
operator|==
operator|*
name|v_cast
operator|<
name|T
operator|>
operator|(
name|b
operator|)
return|;
block|}
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FilteredComparator
operator|<
name|T
operator|,
comment|/* IsAcceptedType = */
name|false
operator|>
block|{
specifier|static
name|bool
name|compare
argument_list|(
argument|const QVariant::Private *
argument_list|,
argument|const QVariant::Private *
argument_list|)
block|{
comment|// It is not possible to construct a QVariant containing not fully defined type
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;
return|return
name|false
return|;
block|}
end_expr_stmt
begin_label
unit|};
name|public
label|:
end_label
begin_expr_stmt
name|QVariantComparator
argument_list|(
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|a
argument_list|,
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|b
argument_list|)
operator|:
name|m_a
argument_list|(
name|a
argument_list|)
operator|,
name|m_b
argument_list|(
argument|b
argument_list|)
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
block|;     }
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|delegate
argument_list|(
argument|const T*
argument_list|)
block|{
return|return
name|FilteredComparator
operator|<
name|T
operator|>
operator|::
name|compare
argument_list|(
name|m_a
argument_list|,
name|m_b
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|bool
name|delegate
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_decl_stmt
name|bool
name|delegate
argument_list|(
specifier|const
name|QMetaTypeSwitcher
operator|::
name|UnknownType
operator|*
argument_list|)
block|{
return|return
name|true
return|;
comment|// for historical reason invalid variant == invalid variant
block|}
end_decl_stmt
begin_decl_stmt
name|bool
name|delegate
argument_list|(
specifier|const
name|QMetaTypeSwitcher
operator|::
name|NotBuiltinType
operator|*
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|m_a
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|m_b
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|Q_CORE_EXPORT
specifier|const
name|QVariant
operator|::
name|Handler
operator|*
name|qcoreVariantHandler
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|Filter
operator|>
name|class
name|QVariantIsNull
block|{
comment|/// \internal
comment|/// This class checks if a type T has method called isNull. Result is kept in the Value property
comment|/// TODO Can we somehow generalize it? A macro version?
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_DECLTYPE
argument_list|)
comment|// C++11 version
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|HasIsNullMethod
block|{         struct
name|Yes
block|{
name|char
name|unused
index|[
literal|1
index|]
block|; }
block|;         struct
name|No
block|{
name|char
name|unused
index|[
literal|2
index|]
block|; }
block|;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|No
argument_list|)
argument_list|)
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|decltype
argument_list|(
argument|static_cast<const C*>(
literal|0
argument|)->isNull()
argument_list|,
argument|Yes()
argument_list|)
name|test
argument_list|(
name|int
argument_list|)
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|No
name|test
argument_list|(
operator|...
argument_list|)
block|;
name|public
operator|:
specifier|static
specifier|const
name|bool
name|Value
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|test
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|)
block|;     }
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
comment|// MSVC 2005, 2008 version: no decltype, but 'sealed' classes (>=2010 has decltype)
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|HasIsNullMethod
block|{         struct
name|Yes
block|{
name|char
name|unused
index|[
literal|1
index|]
block|; }
block|;         struct
name|No
block|{
name|char
name|unused
index|[
literal|2
index|]
block|; }
block|;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|No
argument_list|)
argument_list|)
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|Yes
name|test
argument_list|(
name|char
argument_list|(
operator|*
argument_list|)
index|[
operator|(
operator|&
name|C
operator|::
name|isNull
operator|==
literal|0
operator|)
operator|+
literal|1
index|]
argument_list|)
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|No
name|test
argument_list|(
operator|...
argument_list|)
block|;
name|public
operator|:
specifier|static
specifier|const
name|bool
name|Value
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|test
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|)
block|;     }
block|;
else|#
directive|else
comment|// C++98 version (doesn't work for final classes)
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|IsClass
operator|=
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
operator|>
name|class
name|HasIsNullMethod
block|{         struct
name|Yes
block|{
name|char
name|unused
index|[
literal|1
index|]
block|; }
block|;         struct
name|No
block|{
name|char
name|unused
index|[
literal|2
index|]
block|; }
block|;
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|No
argument_list|)
argument_list|)
block|;          struct
name|FallbackMixin
block|{
name|bool
name|isNull
argument_list|()
specifier|const
block|; }
block|;         struct
name|Derived
operator|:
name|public
name|T
block|,
name|public
name|FallbackMixin
block|{}
block|;
comment|//<- doesn't work for final classes
name|template
operator|<
name|class
name|C
block|,
name|C
operator|>
expr|struct
name|TypeCheck
block|{}
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|Yes
name|test
argument_list|(
operator|...
argument_list|)
block|;
name|template
operator|<
name|class
name|C
operator|>
specifier|static
name|No
name|test
argument_list|(
name|TypeCheck
operator|<
name|bool
argument_list|(
argument|FallbackMixin::*
argument_list|)
operator|(
operator|)
specifier|const
argument_list|,
operator|&
name|C
operator|::
name|isNull
operator|>
operator|*
argument_list|)
block|;
name|public
operator|:
specifier|static
specifier|const
name|bool
name|Value
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|test
operator|<
name|Derived
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|)
block|;     }
block|;
comment|// We need to exclude primitive types as they won't compile with HasIsNullMethod::Check classes
comment|// anyway it is not a problem as the types do not have isNull method.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|HasIsNullMethod
operator|<
name|T
block|,
comment|/* IsClass = */
name|false
operator|>
block|{
name|public
operator|:
specifier|static
specifier|const
name|bool
name|Value
operator|=
name|false
block|;     }
block|;
endif|#
directive|endif
comment|// TODO This part should go to autotests during HasIsNullMethod generalization.
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|HasIsNullMethod
operator|<
name|bool
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTest1
block|{
name|bool
name|isNull
argument_list|()
specifier|const
block|; }
block|;
name|Q_STATIC_ASSERT
argument_list|(
name|HasIsNullMethod
operator|<
name|SelfTest1
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTest2
block|{}
block|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|HasIsNullMethod
operator|<
name|SelfTest2
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTest3
operator|:
name|public
name|SelfTest1
block|{}
block|;
name|Q_STATIC_ASSERT
argument_list|(
name|HasIsNullMethod
operator|<
name|SelfTest3
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTestFinal1
name|Q_DECL_FINAL
block|{
name|bool
name|isNull
argument_list|()
specifier|const
block|; }
block|;
name|Q_STATIC_ASSERT
argument_list|(
name|HasIsNullMethod
operator|<
name|SelfTestFinal1
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTestFinal2
name|Q_DECL_FINAL
block|{}
block|;
name|Q_STATIC_ASSERT
argument_list|(
operator|!
name|HasIsNullMethod
operator|<
name|SelfTestFinal2
operator|>
operator|::
name|Value
argument_list|)
block|;     struct
name|SelfTestFinal3
name|Q_DECL_FINAL
operator|:
name|public
name|SelfTest1
block|{}
block|;
name|Q_STATIC_ASSERT
argument_list|(
name|HasIsNullMethod
operator|<
name|SelfTestFinal3
operator|>
operator|::
name|Value
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|HasIsNull
operator|=
name|HasIsNullMethod
operator|<
name|T
operator|>
operator|::
name|Value
operator|>
expr|struct
name|CallFilteredIsNull
block|{
specifier|static
name|bool
name|isNull
argument_list|(
argument|const QVariant::Private *d
argument_list|)
block|{
return|return
name|v_cast
operator|<
name|T
operator|>
operator|(
name|d
operator|)
operator|->
name|isNull
argument_list|()
return|;
block|}
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CallFilteredIsNull
operator|<
name|T
operator|,
comment|/* HasIsNull = */
name|false
operator|>
block|{
specifier|static
name|bool
name|isNull
argument_list|(
argument|const QVariant::Private *d
argument_list|)
block|{
return|return
name|d
operator|->
name|is_null
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|bool
name|IsAcceptedType
operator|=
name|Filter
operator|::
name|template
name|Acceptor
operator|<
name|T
operator|>
operator|::
name|IsAccepted
operator|>
expr|struct
name|CallIsNull
block|{
specifier|static
name|bool
name|isNull
argument_list|(
argument|const QVariant::Private *d
argument_list|)
block|{
return|return
name|CallFilteredIsNull
operator|<
name|T
operator|>
operator|::
name|isNull
argument_list|(
name|d
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CallIsNull
operator|<
name|T
operator|,
comment|/* IsAcceptedType = */
name|false
operator|>
block|{
specifier|static
name|bool
name|isNull
argument_list|(
argument|const QVariant::Private *d
argument_list|)
block|{
return|return
name|CallFilteredIsNull
operator|<
name|T
operator|,
name|false
operator|>
operator|::
name|isNull
argument_list|(
name|d
argument_list|)
return|;
block|}
end_expr_stmt
begin_label
unit|};
name|public
label|:
end_label
begin_expr_stmt
name|QVariantIsNull
argument_list|(
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|d
argument_list|)
operator|:
name|m_d
argument_list|(
argument|d
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|delegate
argument_list|(
argument|const T*
argument_list|)
block|{
return|return
name|CallIsNull
operator|<
name|T
operator|>
operator|::
name|isNull
argument_list|(
name|m_d
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// we need that as sizof(void) is undefined and it is needed in HasIsNullMethod
end_comment
begin_function
name|bool
name|delegate
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
return|return
name|m_d
operator|->
name|is_null
return|;
block|}
end_function
begin_decl_stmt
name|bool
name|delegate
argument_list|(
specifier|const
name|QMetaTypeSwitcher
operator|::
name|UnknownType
operator|*
argument_list|)
block|{
return|return
name|m_d
operator|->
name|is_null
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|bool
name|delegate
argument_list|(
specifier|const
name|QMetaTypeSwitcher
operator|::
name|NotBuiltinType
operator|*
argument_list|)
block|{
comment|// QVariantIsNull is used only for built-in types
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
expr_stmt|;
return|return
name|m_d
operator|->
name|is_null
return|;
block|}
end_decl_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
specifier|const
name|QVariant
operator|::
name|Private
operator|*
name|m_d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|Filter
operator|>
name|class
name|QVariantConstructor
block|{
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|CanUseInternalSpace
operator|=
name|QVariantIntegrator
operator|<
name|T
operator|>
operator|::
name|CanUseInternalSpace
operator|>
expr|struct
name|CallConstructor
block|{}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CallConstructor
operator|<
name|T
block|,
comment|/* CanUseInternalSpace = */
name|true
operator|>
block|{
name|CallConstructor
argument_list|(
argument|const QVariantConstructor&tc
argument_list|)
block|{
if|if
condition|(
name|tc
operator|.
name|m_copy
condition|)
name|new
argument_list|(
argument|&tc.m_x->data.ptr
argument_list|)
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
name|tc
operator|.
name|m_copy
operator|)
argument_list|)
expr_stmt|;
else|else
name|new
argument_list|(
argument|&tc.m_x->data.ptr
argument_list|)
name|T
argument_list|()
expr_stmt|;
name|tc
operator|.
name|m_x
operator|->
name|is_shared
operator|=
name|false
block|;         }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CallConstructor
operator|<
name|T
operator|,
comment|/* CanUseInternalSpace = */
name|false
operator|>
block|{
name|CallConstructor
argument_list|(
argument|const QVariantConstructor&tc
argument_list|)
block|{
name|Q_STATIC_ASSERT
argument_list|(
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
operator|||
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|QVariant
operator|::
name|Private
operator|::
name|Data
argument_list|)
argument_list|)
block|;
name|tc
operator|.
name|m_x
operator|->
name|data
operator|.
name|shared
operator|=
name|tc
operator|.
name|m_copy
condition|?
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
operator|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|tc
operator|.
name|m_copy
operator|)
operator|)
else|:
name|new
name|QVariantPrivateSharedEx
operator|<
name|T
operator|>
block|;
name|tc
operator|.
name|m_x
operator|->
name|is_shared
operator|=
name|true
block|;         }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|bool
name|IsAcceptedType
operator|=
name|Filter
operator|::
name|template
name|Acceptor
operator|<
name|T
operator|>
operator|::
name|IsAccepted
operator|>
expr|struct
name|FilteredConstructor
block|{
name|FilteredConstructor
argument_list|(
argument|const QVariantConstructor&tc
argument_list|)
block|{
name|CallConstructor
operator|<
name|T
operator|>
name|tmp
argument_list|(
name|tc
argument_list|)
block|;
name|tc
operator|.
name|m_x
operator|->
name|is_null
operator|=
operator|!
name|tc
operator|.
name|m_copy
block|;         }
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FilteredConstructor
operator|<
name|T
operator|,
comment|/* IsAcceptedType = */
name|false
operator|>
block|{
name|FilteredConstructor
argument_list|(
argument|const QVariantConstructor&tc
argument_list|)
block|{
comment|// ignore types that lives outside of the current library
name|tc
operator|.
name|m_x
operator|->
name|type
operator|=
name|QVariant
operator|::
name|Invalid
block|;         }
block|}
expr_stmt|;
end_expr_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|QVariantConstructor
argument_list|(
name|QVariant
operator|::
name|Private
operator|*
name|x
argument_list|,
specifier|const
name|void
operator|*
name|copy
argument_list|)
operator|:
name|m_x
argument_list|(
name|x
argument_list|)
operator|,
name|m_copy
argument_list|(
argument|copy
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|delegate
argument_list|(
argument|const T*
argument_list|)
block|{
name|FilteredConstructor
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|)
block|;     }
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::NotBuiltinType*
argument_list|)
block|{
comment|// QVariantConstructor is used only for built-in types.
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;     }
name|void
name|delegate
argument_list|(
argument|const void*
argument_list|)
block|{
name|qWarning
argument_list|(
literal|"Trying to create a QVariant instance of QMetaType::Void type, an invalid QVariant will be constructed instead"
argument_list|)
block|;
name|m_x
operator|->
name|type
operator|=
name|QMetaType
operator|::
name|UnknownType
block|;
name|m_x
operator|->
name|is_shared
operator|=
name|false
block|;
name|m_x
operator|->
name|is_null
operator|=
operator|!
name|m_copy
block|;     }
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::UnknownType*
argument_list|)
block|{
if|if
condition|(
name|m_x
operator|->
name|type
operator|!=
name|QMetaType
operator|::
name|UnknownType
condition|)
block|{
name|qWarning
argument_list|(
literal|"Trying to construct an instance of an invalid type, type id: %i"
argument_list|,
name|m_x
operator|->
name|type
argument_list|)
expr_stmt|;
name|m_x
operator|->
name|type
operator|=
name|QMetaType
operator|::
name|UnknownType
expr_stmt|;
block|}
name|m_x
operator|->
name|is_shared
operator|=
name|false
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_x
operator|->
name|is_null
operator|=
operator|!
name|m_copy
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|} private:
name|QVariant
operator|::
name|Private
operator|*
name|m_x
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|void
modifier|*
name|m_copy
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|Filter
operator|>
name|class
name|QVariantDestructor
block|{
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|IsAcceptedType
operator|=
name|Filter
operator|::
name|template
name|Acceptor
operator|<
name|T
operator|>
operator|::
name|IsAccepted
operator|>
expr|struct
name|FilteredDestructor
block|{
name|FilteredDestructor
argument_list|(
argument|QVariant::Private *d
argument_list|)
block|{
name|v_clear
operator|<
name|T
operator|>
operator|(
name|d
operator|)
block|;         }
block|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FilteredDestructor
operator|<
name|T
block|,
comment|/* IsAcceptedType = */
name|false
operator|>
block|{
name|FilteredDestructor
argument_list|(
argument|QVariant::Private *
argument_list|)
block|{
comment|// It is not possible to create not accepted type
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;         }
block|}
block|;
name|public
operator|:
name|QVariantDestructor
argument_list|(
name|QVariant
operator|::
name|Private
operator|*
name|d
argument_list|)
operator|:
name|m_d
argument_list|(
argument|d
argument_list|)
block|{}
operator|~
name|QVariantDestructor
argument_list|()
block|{
name|m_d
operator|->
name|type
operator|=
name|QVariant
operator|::
name|Invalid
block|;
name|m_d
operator|->
name|is_null
operator|=
name|true
block|;
name|m_d
operator|->
name|is_shared
operator|=
name|false
block|;     }
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|delegate
argument_list|(
argument|const T*
argument_list|)
block|{
name|FilteredDestructor
operator|<
name|T
operator|>
name|cleaner
argument_list|(
name|m_d
argument_list|)
block|;     }
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::NotBuiltinType*
argument_list|)
block|{
comment|// QVariantDestructor class is used only for a built-in type
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;     }
comment|// Ignore nonconstructible type
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::UnknownType*
argument_list|)
block|{}
name|void
name|delegate
argument_list|(
argument|const void*
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|; }
name|private
operator|:
name|QVariant
operator|::
name|Private
operator|*
name|m_d
block|; }
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QVariantPrivate
block|{
name|Q_CORE_EXPORT
name|void
name|registerHandler
argument_list|(
specifier|const
name|int
comment|/* Modules::Names */
name|name
argument_list|,
specifier|const
name|QVariant
operator|::
name|Handler
operator|*
name|handler
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
name|class
name|Filter
operator|>
name|class
name|QVariantDebugStream
block|{
name|template
operator|<
name|typename
name|T
block|,
name|bool
name|IsAcceptedType
operator|=
name|Filter
operator|::
name|template
name|Acceptor
operator|<
name|T
operator|>
operator|::
name|IsAccepted
operator|>
expr|struct
name|Filtered
block|{
name|Filtered
argument_list|(
argument|QDebug dbg
argument_list|,
argument|QVariant::Private *d
argument_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
operator|*
name|v_cast
operator|<
name|T
operator|>
operator|(
name|d
operator|)
block|;         }
block|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Filtered
operator|<
name|T
block|,
comment|/* IsAcceptedType = */
name|false
operator|>
block|{
name|Filtered
argument_list|(
argument|QDebug
comment|/* dbg */
argument_list|,
argument|QVariant::Private *
argument_list|)
block|{
comment|// It is not possible to construct not acccepted type, QVariantConstructor creates an invalid variant for them
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;         }
block|}
block|;
name|public
operator|:
name|QVariantDebugStream
argument_list|(
argument|QDebug dbg
argument_list|,
argument|QVariant::Private *d
argument_list|)
operator|:
name|m_debugStream
argument_list|(
name|dbg
argument_list|)
block|,
name|m_d
argument_list|(
argument|d
argument_list|)
block|{}
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|delegate
argument_list|(
argument|const T*
argument_list|)
block|{
name|Filtered
operator|<
name|T
operator|>
name|streamIt
argument_list|(
name|m_debugStream
argument_list|,
name|m_d
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|streamIt
argument_list|)
block|;     }
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::NotBuiltinType*
argument_list|)
block|{
comment|// QVariantDebugStream class is used only for a built-in type
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|;     }
name|void
name|delegate
argument_list|(
argument|const QMetaTypeSwitcher::UnknownType*
argument_list|)
block|{
name|m_debugStream
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QVariant::Invalid"
block|;     }
name|void
name|delegate
argument_list|(
argument|const void*
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|false
argument_list|)
block|; }
name|private
operator|:
name|QDebug
name|m_debugStream
block|;
name|QVariant
operator|::
name|Private
operator|*
name|m_d
block|; }
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
comment|// QVARIANT_P_H
end_comment
end_unit
