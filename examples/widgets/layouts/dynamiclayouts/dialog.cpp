begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"dialog.h"
end_include
begin_constructor
DECL|function|Dialog
name|Dialog
operator|::
name|Dialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|createRotableGroupBox
argument_list|()
expr_stmt|;
name|createOptionsGroupBox
argument_list|()
expr_stmt|;
name|createButtonBox
argument_list|()
expr_stmt|;
name|mainLayout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|rotableGroupBox
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|optionsGroupBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetMinimumSize
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Dynamic Layouts"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|buttonsOrientationChanged
name|void
name|Dialog
operator|::
name|buttonsOrientationChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetNoConstraint
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|Orientation
name|orientation
init|=
name|Qt
operator|::
name|Orientation
argument_list|(
name|buttonsOrientationComboBox
operator|->
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|buttonBox
operator|->
name|orientation
argument_list|()
condition|)
return|return;
name|mainLayout
operator|->
name|removeWidget
argument_list|(
name|buttonBox
argument_list|)
expr_stmt|;
name|int
name|spacing
init|=
name|mainLayout
operator|->
name|spacing
argument_list|()
decl_stmt|;
name|QSize
name|oldSizeHint
init|=
name|buttonBox
operator|->
name|sizeHint
argument_list|()
operator|+
name|QSize
argument_list|(
name|spacing
argument_list|,
name|spacing
argument_list|)
decl_stmt|;
name|buttonBox
operator|->
name|setOrientation
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
name|QSize
name|newSizeHint
init|=
name|buttonBox
operator|->
name|sizeHint
argument_list|()
operator|+
name|QSize
argument_list|(
name|spacing
argument_list|,
name|spacing
argument_list|)
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|size
argument_list|()
operator|+
name|QSize
argument_list|(
operator|-
name|oldSizeHint
operator|.
name|width
argument_list|()
argument_list|,
name|newSizeHint
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|size
argument_list|()
operator|+
name|QSize
argument_list|(
name|newSizeHint
operator|.
name|width
argument_list|()
argument_list|,
operator|-
name|oldSizeHint
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetDefaultConstraint
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotateWidgets
name|void
name|Dialog
operator|::
name|rotateWidgets
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|rotableWidgets
operator|.
name|count
argument_list|()
operator|%
literal|2
operator|==
literal|0
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|widget
decl|,
name|rotableWidgets
control|)
name|rotableLayout
operator|->
name|removeWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|rotableWidgets
operator|.
name|enqueue
argument_list|(
name|rotableWidgets
operator|.
name|dequeue
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|n
init|=
name|rotableWidgets
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
operator|/
literal|2
condition|;
operator|++
name|i
control|)
block|{
name|rotableLayout
operator|->
name|addWidget
argument_list|(
name|rotableWidgets
index|[
name|n
operator|-
name|i
operator|-
literal|1
index|]
argument_list|,
literal|0
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|rotableLayout
operator|->
name|addWidget
argument_list|(
name|rotableWidgets
index|[
name|i
index|]
argument_list|,
literal|1
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|help
name|void
name|Dialog
operator|::
name|help
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Dynamic Layouts Help"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"This example shows how to change layouts "
literal|"dynamically."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createRotableGroupBox
name|void
name|Dialog
operator|::
name|createRotableGroupBox
parameter_list|()
block|{
name|rotableGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Rotable Widgets"
argument_list|)
argument_list|)
expr_stmt|;
name|rotableWidgets
operator|.
name|enqueue
argument_list|(
operator|new
name|QSpinBox
argument_list|)
expr_stmt|;
name|rotableWidgets
operator|.
name|enqueue
argument_list|(
operator|new
name|QSlider
argument_list|)
expr_stmt|;
name|rotableWidgets
operator|.
name|enqueue
argument_list|(
operator|new
name|QDial
argument_list|)
expr_stmt|;
name|rotableWidgets
operator|.
name|enqueue
argument_list|(
operator|new
name|QProgressBar
argument_list|)
expr_stmt|;
name|int
name|n
init|=
name|rotableWidgets
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
block|{
name|connect
argument_list|(
name|rotableWidgets
index|[
name|i
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|rotableWidgets
index|[
operator|(
name|i
operator|+
literal|1
operator|)
operator|%
name|n
index|]
argument_list|,
name|SLOT
argument_list|(
name|setValue
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|rotableLayout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|rotableGroupBox
operator|->
name|setLayout
argument_list|(
name|rotableLayout
argument_list|)
expr_stmt|;
name|rotateWidgets
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createOptionsGroupBox
name|void
name|Dialog
operator|::
name|createOptionsGroupBox
parameter_list|()
block|{
name|optionsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonsOrientationLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Orientation of buttons:"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonsOrientationComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|buttonsOrientationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Horizontal"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|buttonsOrientationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Vertical"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonsOrientationComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|buttonsOrientationChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|optionsLayout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|buttonsOrientationLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|addWidget
argument_list|(
name|buttonsOrientationComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|optionsLayout
operator|->
name|setColumnStretch
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|optionsGroupBox
operator|->
name|setLayout
argument_list|(
name|optionsLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createButtonBox
name|void
name|Dialog
operator|::
name|createButtonBox
parameter_list|()
block|{
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
expr_stmt|;
name|closeButton
operator|=
name|buttonBox
operator|->
name|addButton
argument_list|(
name|QDialogButtonBox
operator|::
name|Close
argument_list|)
expr_stmt|;
name|helpButton
operator|=
name|buttonBox
operator|->
name|addButton
argument_list|(
name|QDialogButtonBox
operator|::
name|Help
argument_list|)
expr_stmt|;
name|rotateWidgetsButton
operator|=
name|buttonBox
operator|->
name|addButton
argument_list|(
name|tr
argument_list|(
literal|"Rotate&Widgets"
argument_list|)
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rotateWidgetsButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|rotateWidgets
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|helpButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|help
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
