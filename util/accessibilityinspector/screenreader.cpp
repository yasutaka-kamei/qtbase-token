begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"screenreader.h"
end_include
begin_include
include|#
directive|include
file|"optionswidget.h"
end_include
begin_include
include|#
directive|include
file|"accessibilityscenemanager.h"
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_constructor
DECL|function|ScreenReader
name|ScreenReader
operator|::
name|ScreenReader
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
name|m_selectedInterface
operator|=
literal|0
expr_stmt|;
name|m_rootInterface
operator|=
literal|0
expr_stmt|;
name|bool
name|activateCalled
init|=
literal|false
decl_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~ScreenReader
name|ScreenReader
operator|::
name|~
name|ScreenReader
parameter_list|()
block|{
operator|delete
name|m_selectedInterface
expr_stmt|;
operator|delete
name|m_rootInterface
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setRootObject
name|void
name|ScreenReader
operator|::
name|setRootObject
parameter_list|(
name|QObject
modifier|*
name|rootObject
parameter_list|)
block|{
name|m_rootInterface
operator|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|rootObject
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOptionsWidget
name|void
name|ScreenReader
operator|::
name|setOptionsWidget
parameter_list|(
name|OptionsWidget
modifier|*
name|optionsWidget
parameter_list|)
block|{
name|m_optionsWidget
operator|=
name|optionsWidget
expr_stmt|;
block|}
end_function
begin_function
DECL|function|touchPoint
name|void
name|ScreenReader
operator|::
name|touchPoint
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"touch"
operator|<<
name|point
expr_stmt|;
comment|// Wait and see if this touch is the start of a double-tap
comment|// (activate will then be called and cancel the touch processing)
name|m_activateCalled
operator|=
literal|false
expr_stmt|;
name|m_currentTouchPoint
operator|=
name|point
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|200
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|processTouchPoint
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processTouchPoint
name|void
name|ScreenReader
operator|::
name|processTouchPoint
parameter_list|()
block|{
if|if
condition|(
name|m_activateCalled
condition|)
block|{
return|return;
block|}
if|if
condition|(
name|m_rootInterface
operator|==
literal|0
condition|)
block|{
return|return;
block|}
name|QAccessibleInterface
modifier|*
name|currentInterface
init|=
name|m_rootInterface
decl_stmt|;
name|int
name|hit
init|=
operator|-
literal|2
decl_stmt|;
name|int
name|guardCounter
init|=
literal|0
decl_stmt|;
specifier|const
name|int
name|guardMax
init|=
literal|40
decl_stmt|;
while|while
condition|(
name|currentInterface
operator|!=
literal|0
condition|)
block|{
operator|++
name|guardCounter
expr_stmt|;
if|if
condition|(
name|guardCounter
operator|>
name|guardMax
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"touchPoint exit recursion overflow"
expr_stmt|;
return|return;
comment|// outside
block|}
name|QAccessibleInterface
modifier|*
name|hit
init|=
name|currentInterface
operator|->
name|childAt
argument_list|(
name|m_currentTouchPoint
operator|.
name|x
argument_list|()
argument_list|,
name|m_currentTouchPoint
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hit
condition|)
break|break;
name|currentInterface
operator|=
name|hit
expr_stmt|;
block|}
name|m_selectedInterface
operator|=
name|currentInterface
expr_stmt|;
emit|emit
name|selected
argument_list|(
name|m_selectedInterface
operator|->
name|object
argument_list|()
argument_list|)
emit|;
if|if
condition|(
name|m_optionsWidget
operator|->
name|enableTextToSpeach
argument_list|()
condition|)
name|speak
argument_list|(
name|m_selectedInterface
operator|->
name|text
argument_list|(
name|QAccessible
operator|::
name|Name
argument_list|)
comment|/*+ "," + translateRole(m_selectedInterface->role(0)) */
argument_list|)
expr_stmt|;
comment|//    qDebug()<< "touchPoint exit found"<< m_selectedInterface->text(QAccessible::Name, 0)<< m_selectedInterface->object()<< m_selectedInterface->rect(0);
block|}
end_function
begin_function
DECL|function|activate
name|void
name|ScreenReader
operator|::
name|activate
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ScreenReader::activate"
expr_stmt|;
name|m_activateCalled
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|m_selectedInterface
condition|)
block|{
name|m_selectedInterface
operator|->
name|actionInterface
argument_list|()
operator|->
name|doAction
argument_list|(
name|QAccessibleActionInterface
operator|::
name|pressAction
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|speak
name|void
name|ScreenReader
operator|::
name|speak
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/*voice*/
parameter_list|)
block|{
name|QFile
name|f
argument_list|(
literal|"festivalspeachhack"
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|f
operator|.
name|write
argument_list|(
name|text
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
name|QProcess
modifier|*
name|process
init|=
operator|new
name|QProcess
decl_stmt|;
name|process
operator|->
name|start
argument_list|(
literal|"/usr/bin/festival"
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"--tts"
operator|<<
literal|"festivalspeachhack"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
