begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_RUNBASE_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_RUNBASE_H
define|#
directive|define
name|QTCONCURRENT_RUNBASE_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrent_global.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qfuture.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrunnable.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthreadpool.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|Q_QDOC
name|namespace
name|QtConcurrent
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SelectSpecialization
block|{
name|template
operator|<
name|class
name|Normal
block|,
name|class
name|Void
operator|>
expr|struct
name|Type
block|{
typedef|typedef
name|Normal
name|type
typedef|;
block|}
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|SelectSpecialization
operator|<
name|void
operator|>
block|{
name|template
operator|<
name|class
name|Normal
block|,
name|class
name|Void
operator|>
expr|struct
name|Type
block|{
typedef|typedef
name|Void
name|type
typedef|;
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RunFunctionTaskBase
operator|:
name|public
name|QFutureInterface
operator|<
name|T
operator|>
operator|,
name|public
name|QRunnable
block|{
name|public
operator|:
name|QFuture
operator|<
name|T
operator|>
name|start
argument_list|()
block|{
return|return
name|start
argument_list|(
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
argument_list|)
return|;
block|}
name|QFuture
operator|<
name|T
operator|>
name|start
argument_list|(
argument|QThreadPool *pool
argument_list|)
block|{
name|this
operator|->
name|setThreadPool
argument_list|(
name|pool
argument_list|)
block|;
name|this
operator|->
name|setRunnable
argument_list|(
name|this
argument_list|)
block|;
name|this
operator|->
name|reportStarted
argument_list|()
block|;
name|QFuture
operator|<
name|T
operator|>
name|theFuture
operator|=
name|this
operator|->
name|future
argument_list|()
block|;
name|pool
operator|->
name|start
argument_list|(
name|this
argument_list|,
comment|/*m_priority*/
literal|0
argument_list|)
block|;
return|return
name|theFuture
return|;
block|}
name|void
name|run
argument_list|()
block|{}
name|virtual
name|void
name|runFunctor
argument_list|()
operator|=
literal|0
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|RunFunctionTask
operator|:
name|public
name|RunFunctionTaskBase
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|void
name|run
argument_list|()
block|{
if|if
condition|(
name|this
operator|->
name|isCanceled
argument_list|()
condition|)
block|{
name|this
operator|->
name|reportFinished
argument_list|()
expr_stmt|;
return|return;
block|}
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|try
block|{
endif|#
directive|endif
name|this
operator|->
name|runFunctor
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
block|}
name|catch
argument_list|(
argument|QException&e
argument_list|)
block|{
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportException
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|QFutureInterface
operator|<
name|T
operator|>
operator|::
name|reportException
argument_list|(
name|QUnhandledException
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|this
operator|->
name|reportResult
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|this
operator|->
name|reportFinished
argument_list|()
block|;     }
name|T
name|result
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|RunFunctionTask
operator|<
name|void
operator|>
operator|:
name|public
name|RunFunctionTaskBase
operator|<
name|void
operator|>
block|{
name|public
operator|:
name|void
name|run
argument_list|()
block|{
if|if
condition|(
name|this
operator|->
name|isCanceled
argument_list|()
condition|)
block|{
name|this
operator|->
name|reportFinished
argument_list|()
expr_stmt|;
return|return;
block|}
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
name|try
block|{
endif|#
directive|endif
name|this
operator|->
name|runFunctor
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
block|}
name|catch
argument_list|(
argument|QException&e
argument_list|)
block|{
name|QFutureInterface
operator|<
name|void
operator|>
operator|::
name|reportException
argument_list|(
name|e
argument_list|)
block|;         }
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|QFutureInterface
operator|<
name|void
operator|>
operator|::
name|reportException
argument_list|(
name|QUnhandledException
argument_list|()
argument_list|)
block|;         }
endif|#
directive|endif
name|this
operator|->
name|reportFinished
argument_list|()
block|;     }
end_expr_stmt
begin_comment
unit|};  }
comment|//namespace QtConcurrent
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_QDOC
end_comment
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
