begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of internal files.  This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
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
begin_ifndef
ifndef|#
directive|ifndef
name|QSCOPEDPOINTER_P_H
end_ifndef
begin_define
DECL|macro|QSCOPEDPOINTER_P_H
define|#
directive|define
name|QSCOPEDPOINTER_P_H
end_define
begin_include
include|#
directive|include
file|"QtCore/qscopedpointer.h"
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
comment|/* Internal helper class - exposes the data through data_ptr (legacy from QShared).    Required for some internal Qt classes, do not use otherwise. */
DECL|variable|T
DECL|variable|Cleanup
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Cleanup
operator|=
name|QScopedPointerDeleter
operator|<
name|T
operator|>
expr|>
name|class
name|QCustomScopedPointer
operator|:
name|public
name|QScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
block|{
name|public
operator|:
name|explicit
specifier|inline
name|QCustomScopedPointer
argument_list|(
name|T
operator|*
name|p
operator|=
literal|0
argument_list|)
operator|:
name|QScopedPointer
operator|<
name|T
block|,
name|Cleanup
operator|>
operator|(
name|p
operator|)
block|{     }
specifier|inline
name|T
operator|*
operator|&
name|data_ptr
argument_list|()
block|{
return|return
name|this
operator|->
name|d
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QCustomScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QCustomScopedPointer
operator|<
name|T
operator|,
name|Cleanup
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|d
operator|!=
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QCustomScopedPointer
argument_list|)
end_macro
begin_comment
unit|};
comment|/* Internal helper class - a handler for QShared* classes, to be used in QCustomScopedPointer */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QScopedPointerSharedDeleter
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
name|cleanup
argument_list|(
argument|T *d
argument_list|)
block|{
if|if
condition|(
name|d
operator|&&
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|delete
name|d
decl_stmt|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|/* Internal.    This class is basically a scoped pointer pointing to a ref-counted object  */
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|variable|T
name|class
name|QScopedSharedPointer
operator|:
name|public
name|QCustomScopedPointer
operator|<
name|T
operator|,
name|QScopedPointerSharedDeleter
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
name|explicit
specifier|inline
name|QScopedSharedPointer
argument_list|(
name|T
operator|*
name|p
operator|=
literal|0
argument_list|)
operator|:
name|QCustomScopedPointer
operator|<
name|T
block|,
name|QScopedPointerSharedDeleter
operator|<
name|T
operator|>
expr|>
operator|(
name|p
operator|)
block|{     }
specifier|inline
name|void
name|detach
argument_list|()
block|{
name|qAtomicDetach
argument_list|(
name|this
operator|->
name|d
argument_list|)
block|;     }
specifier|inline
name|void
name|assign
argument_list|(
argument|T *other
argument_list|)
block|{
if|if
condition|(
name|this
operator|->
name|d
operator|==
name|other
condition|)
return|return;
if|if
condition|(
name|other
condition|)
name|other
operator|->
name|ref
operator|.
name|ref
argument_list|()
expr_stmt|;
name|T
operator|*
name|oldD
operator|=
name|this
operator|->
name|d
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|this
operator|->
name|d
operator|=
name|other
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QScopedPointerSharedDeleter
operator|<
name|T
operator|>
operator|::
name|cleanup
argument_list|(
name|oldD
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}      inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QScopedSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|d
operator|==
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QScopedSharedPointer
operator|<
name|T
operator|>
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|d
operator|!=
name|other
operator|.
name|d
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QScopedSharedPointer
argument_list|)
end_macro
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
