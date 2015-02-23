begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2014 by Southwest Research Institute (R) ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
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
begin_typedef
DECL|typedef|QByteArrayList
typedef|typedef
name|QList
operator|<
name|QByteArray
operator|>
name|QByteArrayList
expr_stmt|;
end_typedef
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_QDOC
end_ifdef
begin_decl_stmt
name|class
name|QByteArrayList
range|:
name|public
name|QList
operator|<
name|QByteArray
operator|>
else|#
directive|else
name|template
operator|<
operator|>
expr|struct
name|QListSpecialMethods
operator|<
name|QByteArray
operator|>
endif|#
directive|endif
block|{
name|public
operator|:
specifier|inline
name|QByteArray
name|join
argument_list|()
specifier|const
block|{
return|return
name|QtPrivate
operator|::
name|QByteArrayList_join
argument_list|(
name|self
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|inline
name|QByteArray
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
name|self
argument_list|()
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
specifier|inline
name|QByteArray
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
name|self
argument_list|()
argument_list|,
operator|&
name|sep
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|private
operator|:
typedef|typedef
name|QList
operator|<
name|QByteArray
operator|>
name|Self
expr_stmt|;
name|Self
operator|*
name|self
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|Self
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
specifier|const
name|Self
operator|*
name|self
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|Self
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
