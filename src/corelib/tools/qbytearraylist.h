begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 by Southwest Research Institute (R) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBYTEARRAYLIST_H
end_ifndef
begin_define
DECL|macro|QBYTEARRAYLIST_H
define|#
directive|define
name|QBYTEARRAYLIST_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QByteArrayListIterator
typedef|typedef
name|QListIterator
operator|<
name|QByteArray
operator|>
name|QByteArrayListIterator
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QMutableByteArrayListIterator
typedef|typedef
name|QMutableListIterator
operator|<
name|QByteArray
operator|>
name|QMutableByteArrayListIterator
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QByteArrayList
range|:
name|public
name|QList
operator|<
name|QByteArray
operator|>
block|{
name|public
operator|:
name|QByteArrayList
argument_list|()
block|{ }
name|explicit
name|QByteArrayList
argument_list|(
argument|const QByteArray&i
argument_list|)
block|{
name|append
argument_list|(
name|i
argument_list|)
block|; }
name|QByteArrayList
argument_list|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|l
argument_list|)
operator|:
name|QList
operator|<
name|QByteArray
operator|>
operator|(
name|l
operator|)
block|{ }
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QByteArrayList
argument_list|(
name|QList
operator|<
name|QByteArray
operator|>
operator|&&
name|l
argument_list|)
operator|:
name|QList
operator|<
name|QByteArray
operator|>
operator|(
name|qMove
argument_list|(
name|l
argument_list|)
operator|)
block|{ }
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
name|QByteArrayList
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|QByteArray
operator|>
name|args
argument_list|)
operator|:
name|QList
operator|<
name|QByteArray
operator|>
operator|(
name|args
operator|)
block|{ }
endif|#
directive|endif
comment|// compiler-generated copy/move ctor/assignment operators are ok
comment|// compiler-generated dtor is ok
comment|// inherited swap() is ok (sic!)
comment|// For the operators, we could just say using QList<QByteArray>::operator{=,<<},
comment|// but they would not return QByteArrayList&, so we need to write inline forwarders:
name|QByteArrayList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|other
operator|)
block|{
name|QList
operator|<
name|QByteArray
operator|>
operator|::
name|operator
operator|=
operator|(
name|other
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QByteArrayList
operator|&
name|operator
operator|=
operator|(
name|QList
operator|<
name|QByteArray
operator|>
operator|&&
name|other
operator|)
block|{
name|QList
operator|<
name|QByteArray
operator|>
operator|::
name|operator
operator|=
operator|(
name|qMove
argument_list|(
name|other
argument_list|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
comment|// if this is missing, assignment from an initializer_list is ambiguous:
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
name|QByteArrayList
operator|&
name|operator
operator|=
operator|(
name|std
operator|::
name|initializer_list
operator|<
name|QByteArray
operator|>
name|args
operator|)
block|{
name|QByteArrayList
name|copy
argument_list|(
name|args
argument_list|)
block|;
name|swap
argument_list|(
name|copy
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QByteArrayList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QByteArray
operator|&
name|str
operator|)
block|{
name|QList
operator|<
name|QByteArray
operator|>
operator|::
name|operator
operator|<<
operator|(
name|str
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|QByteArrayList
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|l
operator|)
block|{
name|QList
operator|<
name|QByteArray
operator|>
operator|::
name|operator
operator|<<
operator|(
name|l
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|//
comment|// actual functionality provided on top of what QList<QByteArray> provides starts here:
comment|//
specifier|inline
name|QByteArray
name|join
argument_list|()
specifier|const
block|;
specifier|inline
name|QByteArray
name|join
argument_list|(
argument|const QByteArray&sep
argument_list|)
specifier|const
block|;
specifier|inline
name|QByteArray
name|join
argument_list|(
argument|char sep
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QByteArrayList
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QtPrivate
block|{
name|QByteArray
name|Q_CORE_EXPORT
name|QByteArrayList_join
parameter_list|(
specifier|const
name|QByteArrayList
modifier|*
name|that
parameter_list|,
specifier|const
name|char
modifier|*
name|separator
parameter_list|,
name|int
name|separatorLength
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|join
specifier|inline
name|QByteArray
name|QByteArrayList
operator|::
name|join
argument_list|()
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QByteArrayList_join
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|join
specifier|inline
name|QByteArray
name|QByteArrayList
operator|::
name|join
argument_list|(
argument|const QByteArray&sep
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QByteArrayList_join
argument_list|(
name|this
argument_list|,
name|sep
operator|.
name|constData
argument_list|()
argument_list|,
name|sep
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|join
specifier|inline
name|QByteArray
name|QByteArrayList
operator|::
name|join
argument_list|(
argument|char sep
argument_list|)
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QByteArrayList_join
argument_list|(
name|this
argument_list|,
operator|&
name|sep
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QByteArrayList
name|operator
operator|+
operator|(
specifier|const
name|QByteArrayList
operator|&
name|lhs
operator|,
specifier|const
name|QByteArrayList
operator|&
name|rhs
operator|)
block|{
name|QByteArrayList
name|res
operator|=
name|lhs
block|;
name|res
operator|+=
name|rhs
block|;
return|return
name|res
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QByteArrayList
name|operator
operator|+
operator|(
name|QByteArrayList
operator|&&
name|lhs
operator|,
specifier|const
name|QByteArrayList
operator|&
name|rhs
operator|)
block|{
name|lhs
operator|+=
name|rhs
block|;
return|return
name|qMove
argument_list|(
name|lhs
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QByteArrayList
name|operator
operator|+
operator|(
specifier|const
name|QByteArrayList
operator|&
name|lhs
operator|,
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|rhs
operator|)
block|{
name|QByteArrayList
name|res
operator|=
name|lhs
block|;
name|res
operator|+=
name|rhs
block|;
return|return
name|res
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QByteArrayList
name|operator
operator|+
operator|(
name|QByteArrayList
operator|&&
name|lhs
operator|,
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|rhs
operator|)
block|{
name|lhs
operator|+=
name|rhs
block|;
return|return
name|qMove
argument_list|(
name|lhs
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|inline
name|QByteArrayList
name|operator
operator|+
operator|(
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|lhs
operator|,
specifier|const
name|QByteArrayList
operator|&
name|rhs
operator|)
block|{
name|QByteArrayList
name|res
operator|=
name|lhs
block|;
name|res
operator|+=
name|rhs
block|;
return|return
name|res
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// ambiguous with QList<QByteArray>::operator+(const QList<QByteArray>&) const
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_endif
unit|inline QByteArrayList operator+(QList<QByteArray>&&lhs, const QByteArrayList&rhs) {     lhs += rhs;     return qMove(lhs); }
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
specifier|inline
name|QByteArrayList
operator|&
name|operator
operator|+=
operator|(
name|QByteArrayList
operator|&
name|lhs
operator|,
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
name|rhs
operator|)
block|{
name|lhs
operator|.
name|append
argument_list|(
name|rhs
argument_list|)
block|;
return|return
name|lhs
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
specifier|inline
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QByteArrayList
operator|&
name|list
operator|)
block|{
return|return
name|operator
operator|>>
operator|(
name|in
operator|,
name|static_cast
operator|<
name|QList
operator|<
name|QByteArray
operator|>
operator|&
operator|>
operator|(
name|list
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QByteArrayList
operator|&
name|list
operator|)
block|{
return|return
name|operator
operator|<<
operator|(
name|out
operator|,
name|static_cast
operator|<
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
operator|&
operator|>
operator|(
name|list
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
comment|// QT_NO_DATASTREAM
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBYTEARRAYLIST_H
end_comment
end_unit