begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSTHREADPOOLRUNNER_H
end_ifndef
begin_define
DECL|macro|QWINDOWSTHREADPOOLRUNNER_H
define|#
directive|define
name|QWINDOWSTHREADPOOLRUNNER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRunnable>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThreadPool>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWaitCondition>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QWindowsThreadPoolRunner     \brief Runs a task in the global instance of QThreadPool      QThreadPool does not provide a method to wait on a single task, so this needs     to be done by using QWaitCondition/QMutex.      \internal     \ingroup qt-lighthouse-win */
name|class
name|QWindowsThreadPoolRunner
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsThreadPoolRunner
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|template
operator|<
name|class
name|RunnableFunction
operator|>
comment|// nested class implementing QRunnable to execute a function.
name|class
name|Runnable
operator|:
name|public
name|QRunnable
block|{
name|public
operator|:
name|explicit
name|Runnable
argument_list|(
argument|QMutex *m
argument_list|,
argument|QWaitCondition *c
argument_list|,
argument|RunnableFunction f
argument_list|)
operator|:
name|m_mutex
argument_list|(
name|m
argument_list|)
block|,
name|m_condition
argument_list|(
name|c
argument_list|)
block|,
name|m_function
argument_list|(
argument|f
argument_list|)
block|{}
name|void
name|run
argument_list|()
name|Q_DECL_OVERRIDE
block|{
name|m_function
argument_list|()
block|;
name|m_mutex
operator|->
name|lock
argument_list|()
block|;
name|m_condition
operator|->
name|wakeAll
argument_list|()
block|;
name|m_mutex
operator|->
name|unlock
argument_list|()
block|;         }
name|private
operator|:
name|QMutex
operator|*
name|m_mutex
block|;
name|QWaitCondition
operator|*
name|m_condition
block|;
name|RunnableFunction
name|m_function
block|;     }
expr_stmt|;
comment|// class Runnable
name|public
label|:
name|QWindowsThreadPoolRunner
argument_list|()
block|{}
name|template
operator|<
name|class
name|Function
operator|>
name|bool
name|run
argument_list|(
argument|Function f
argument_list|,
argument|unsigned long timeOutMSecs =
literal|5000
argument_list|)
block|{
name|QThreadPool
operator|*
name|pool
operator|=
name|QThreadPool
operator|::
name|globalInstance
argument_list|()
block|;
name|Q_ASSERT
argument_list|(
name|pool
argument_list|)
block|;
name|Runnable
operator|<
name|Function
operator|>
operator|*
name|runnable
operator|=
name|new
name|Runnable
operator|<
name|Function
operator|>
operator|(
operator|&
name|m_mutex
operator|,
operator|&
name|m_condition
operator|,
name|f
operator|)
block|;
name|m_mutex
operator|.
name|lock
argument_list|()
block|;
name|pool
operator|->
name|start
argument_list|(
name|runnable
argument_list|)
block|;
specifier|const
name|bool
name|ok
operator|=
name|m_condition
operator|.
name|wait
argument_list|(
operator|&
name|m_mutex
argument_list|,
name|timeOutMSecs
argument_list|)
block|;
name|m_mutex
operator|.
name|unlock
argument_list|()
block|;
if|if
condition|(
operator|!
name|ok
condition|)
name|pool
operator|->
name|cancel
argument_list|(
name|runnable
argument_list|)
expr_stmt|;
return|return
name|ok
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QMutex
name|m_mutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWaitCondition
name|m_condition
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !QT_NO_THREAD
end_comment
begin_label
name|public
label|:
end_label
begin_macro
name|QWindowsThreadPoolRunner
argument_list|()
end_macro
begin_block
block|{}
end_block
begin_expr_stmt
name|template
operator|<
name|class
name|Function
operator|>
name|bool
name|run
argument_list|(
argument|Function f
argument_list|,
argument|unsigned long
comment|/* timeOutMSecs */
argument|=
literal|5000
argument_list|)
block|{
name|f
argument_list|()
block|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSTHREADPOOLRUNNER_H
end_comment
end_unit
