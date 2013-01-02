begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"locationdialog.h"
end_include
begin_constructor
DECL|function|LocationDialog
name|LocationDialog
operator|::
name|LocationDialog
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
name|formatComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Native"
argument_list|)
argument_list|)
expr_stmt|;
name|formatComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"INI"
argument_list|)
argument_list|)
expr_stmt|;
name|scopeComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|scopeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"User"
argument_list|)
argument_list|)
expr_stmt|;
name|scopeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"System"
argument_list|)
argument_list|)
expr_stmt|;
name|organizationComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|organizationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
expr_stmt|;
name|organizationComboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|applicationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Any"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Application Example"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Assistant"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Designer"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Linguist"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|applicationComboBox
operator|->
name|setCurrentIndex
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|formatLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Format:"
argument_list|)
argument_list|)
expr_stmt|;
name|formatLabel
operator|->
name|setBuddy
argument_list|(
name|formatComboBox
argument_list|)
expr_stmt|;
name|scopeLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Scope:"
argument_list|)
argument_list|)
expr_stmt|;
name|scopeLabel
operator|->
name|setBuddy
argument_list|(
name|scopeComboBox
argument_list|)
expr_stmt|;
name|organizationLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Organization:"
argument_list|)
argument_list|)
expr_stmt|;
name|organizationLabel
operator|->
name|setBuddy
argument_list|(
name|organizationComboBox
argument_list|)
expr_stmt|;
name|applicationLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Application:"
argument_list|)
argument_list|)
expr_stmt|;
name|applicationLabel
operator|->
name|setBuddy
argument_list|(
name|applicationComboBox
argument_list|)
expr_stmt|;
name|locationsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Setting Locations"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|labels
decl_stmt|;
name|labels
operator|<<
name|tr
argument_list|(
literal|"Location"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Access"
argument_list|)
expr_stmt|;
name|locationsTable
operator|=
operator|new
name|QTableWidget
expr_stmt|;
name|locationsTable
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setEditTriggers
argument_list|(
name|QAbstractItemView
operator|::
name|NoEditTriggers
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setColumnCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setHorizontalHeaderLabels
argument_list|(
name|labels
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|0
argument_list|,
name|QHeaderView
operator|::
name|Stretch
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|resizeSection
argument_list|(
literal|1
argument_list|,
literal|180
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|formatComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateLocationsTable
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|scopeComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateLocationsTable
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|organizationComboBox
operator|->
name|lineEdit
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateLocationsTable
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|applicationComboBox
operator|->
name|lineEdit
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateLocationsTable
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|accept
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|buttonBox
argument_list|,
name|SIGNAL
argument_list|(
name|rejected
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|locationsLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|locationsLayout
operator|->
name|addWidget
argument_list|(
name|locationsTable
argument_list|)
expr_stmt|;
name|locationsGroupBox
operator|->
name|setLayout
argument_list|(
name|locationsLayout
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|formatLabel
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
name|formatComboBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|scopeLabel
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
name|scopeComboBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|organizationLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|organizationComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|applicationLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|applicationComboBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|locationsGroupBox
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|updateLocationsTable
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Open Application Settings"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|650
argument_list|,
literal|400
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|format
name|QSettings
operator|::
name|Format
name|LocationDialog
operator|::
name|format
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|formatComboBox
operator|->
name|currentIndex
argument_list|()
operator|==
literal|0
condition|)
return|return
name|QSettings
operator|::
name|NativeFormat
return|;
else|else
return|return
name|QSettings
operator|::
name|IniFormat
return|;
block|}
end_function
begin_function
DECL|function|scope
name|QSettings
operator|::
name|Scope
name|LocationDialog
operator|::
name|scope
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|scopeComboBox
operator|->
name|currentIndex
argument_list|()
operator|==
literal|0
condition|)
return|return
name|QSettings
operator|::
name|UserScope
return|;
else|else
return|return
name|QSettings
operator|::
name|SystemScope
return|;
block|}
end_function
begin_function
DECL|function|organization
name|QString
name|LocationDialog
operator|::
name|organization
parameter_list|()
specifier|const
block|{
return|return
name|organizationComboBox
operator|->
name|currentText
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|application
name|QString
name|LocationDialog
operator|::
name|application
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|applicationComboBox
operator|->
name|currentText
argument_list|()
operator|==
name|tr
argument_list|(
literal|"Any"
argument_list|)
condition|)
return|return
literal|""
return|;
else|else
return|return
name|applicationComboBox
operator|->
name|currentText
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|updateLocationsTable
name|void
name|LocationDialog
operator|::
name|updateLocationsTable
parameter_list|()
block|{
name|locationsTable
operator|->
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setRowCount
argument_list|(
literal|0
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|==
literal|0
operator|&&
name|scope
argument_list|()
operator|==
name|QSettings
operator|::
name|SystemScope
condition|)
continue|continue;
name|QSettings
operator|::
name|Scope
name|actualScope
init|=
operator|(
name|i
operator|==
literal|0
operator|)
condition|?
name|QSettings
operator|::
name|UserScope
else|:
name|QSettings
operator|::
name|SystemScope
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
literal|2
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|j
operator|==
literal|0
operator|&&
name|application
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|QString
name|actualApplication
decl_stmt|;
if|if
condition|(
name|j
operator|==
literal|0
condition|)
name|actualApplication
operator|=
name|application
argument_list|()
expr_stmt|;
name|QSettings
name|settings
argument_list|(
name|format
argument_list|()
argument_list|,
name|actualScope
argument_list|,
name|organization
argument_list|()
argument_list|,
name|actualApplication
argument_list|)
decl_stmt|;
name|int
name|row
init|=
name|locationsTable
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|locationsTable
operator|->
name|setRowCount
argument_list|(
name|row
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QTableWidgetItem
modifier|*
name|item0
init|=
operator|new
name|QTableWidgetItem
decl_stmt|;
name|item0
operator|->
name|setText
argument_list|(
name|settings
operator|.
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
name|QTableWidgetItem
modifier|*
name|item1
init|=
operator|new
name|QTableWidgetItem
decl_stmt|;
name|bool
name|disable
init|=
operator|(
name|settings
operator|.
name|childKeys
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|settings
operator|.
name|childGroups
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|row
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|settings
operator|.
name|isWritable
argument_list|()
condition|)
block|{
name|item1
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Read-write"
argument_list|)
argument_list|)
expr_stmt|;
name|disable
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|item1
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Read-only"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|buttonBox
operator|->
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
operator|->
name|setDisabled
argument_list|(
name|disable
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|item1
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Read-only fallback"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|disable
condition|)
block|{
name|item0
operator|->
name|setFlags
argument_list|(
name|item0
operator|->
name|flags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
expr_stmt|;
name|item1
operator|->
name|setFlags
argument_list|(
name|item1
operator|->
name|flags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|ItemIsEnabled
argument_list|)
expr_stmt|;
block|}
name|locationsTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|item0
argument_list|)
expr_stmt|;
name|locationsTable
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|item1
argument_list|)
expr_stmt|;
block|}
block|}
name|locationsTable
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
