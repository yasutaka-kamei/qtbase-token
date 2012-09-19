begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IMAGECOMPOSER_H
end_ifndef
begin_define
DECL|macro|IMAGECOMPOSER_H
define|#
directive|define
name|IMAGECOMPOSER_H
end_define
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QToolButton
name|class
name|QToolButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|ImageComposer
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ImageComposer
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|chooseSource
argument_list|()
block|;
name|void
name|chooseDestination
argument_list|()
block|;
name|void
name|recalculateResult
argument_list|()
block|;
comment|//! [0]
comment|//! [1]
name|private
operator|:
name|void
name|addOp
argument_list|(
argument|QPainter::CompositionMode mode
argument_list|,
argument|const QString&name
argument_list|)
block|;
name|void
name|chooseImage
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|QImage
operator|*
name|image
argument_list|,
name|QToolButton
operator|*
name|button
argument_list|)
block|;
name|void
name|loadImage
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QImage
operator|*
name|image
argument_list|,
name|QToolButton
operator|*
name|button
argument_list|)
block|;
name|QPainter
operator|::
name|CompositionMode
name|currentMode
argument_list|()
specifier|const
block|;
name|QPoint
name|imagePos
argument_list|(
argument|const QImage&image
argument_list|)
specifier|const
block|;
name|QToolButton
operator|*
name|sourceButton
block|;
name|QToolButton
operator|*
name|destinationButton
block|;
name|QComboBox
operator|*
name|operatorComboBox
block|;
name|QLabel
operator|*
name|equalLabel
block|;
name|QLabel
operator|*
name|resultLabel
block|;
name|QImage
name|sourceImage
block|;
name|QImage
name|destinationImage
block|;
name|QImage
name|resultImage
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
