begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"propertywatcher.h"
end_include
begin_include
include|#
directive|include
file|<QMetaProperty>
end_include
begin_include
include|#
directive|include
file|<QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|"propertyfield.h"
end_include
begin_constructor
DECL|function|PropertyWatcher
name|PropertyWatcher
operator|::
name|PropertyWatcher
parameter_list|(
name|QObject
modifier|*
name|subject
parameter_list|,
name|QString
name|annotation
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_subject
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_formLayout
argument_list|(
operator|new
name|QFormLayout
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|setMinimumSize
argument_list|(
literal|450
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|m_formLayout
operator|->
name|setFieldGrowthPolicy
argument_list|(
name|QFormLayout
operator|::
name|ExpandingFieldsGrow
argument_list|)
expr_stmt|;
name|setSubject
argument_list|(
name|subject
argument_list|,
name|annotation
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|UpdatesEnabledBlocker
class|class
name|UpdatesEnabledBlocker
block|{
name|Q_DISABLE_COPY
parameter_list|(
name|UpdatesEnabledBlocker
parameter_list|)
constructor_decl|;
public|public:
DECL|function|UpdatesEnabledBlocker
specifier|explicit
name|UpdatesEnabledBlocker
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
member_init_list|:
name|m_widget
argument_list|(
name|w
argument_list|)
block|{
name|m_widget
operator|->
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
DECL|function|~UpdatesEnabledBlocker
name|~
name|UpdatesEnabledBlocker
parameter_list|()
block|{
name|m_widget
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_widget
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_widget
name|QWidget
modifier|*
name|m_widget
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|setSubject
name|void
name|PropertyWatcher
operator|::
name|setSubject
parameter_list|(
name|QObject
modifier|*
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|annotation
parameter_list|)
block|{
if|if
condition|(
name|s
operator|==
name|m_subject
condition|)
return|return;
name|UpdatesEnabledBlocker
name|blocker
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_subject
condition|)
block|{
name|disconnect
argument_list|(
name|m_subject
argument_list|,
operator|&
name|QObject
operator|::
name|destroyed
argument_list|,
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|subjectDestroyed
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|m_formLayout
operator|->
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|QLayoutItem
modifier|*
name|item
init|=
name|m_formLayout
operator|->
name|takeAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
operator|delete
name|item
operator|->
name|widget
argument_list|()
expr_stmt|;
operator|delete
name|item
expr_stmt|;
block|}
name|window
argument_list|()
operator|->
name|setWindowTitle
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|window
argument_list|()
operator|->
name|setWindowIconText
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|m_subject
operator|=
name|s
expr_stmt|;
if|if
condition|(
operator|!
name|m_subject
condition|)
return|return;
specifier|const
name|QMetaObject
modifier|*
name|meta
init|=
name|m_subject
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|QString
name|title
init|=
name|QLatin1String
argument_list|(
literal|"Properties "
argument_list|)
operator|+
name|QLatin1String
argument_list|(
name|meta
operator|->
name|className
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|m_subject
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|title
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|+
name|m_subject
operator|->
name|objectName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|annotation
operator|.
name|isEmpty
argument_list|()
condition|)
name|title
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|+
name|annotation
expr_stmt|;
name|window
argument_list|()
operator|->
name|setWindowTitle
argument_list|(
name|title
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|count
init|=
name|meta
operator|->
name|propertyCount
argument_list|()
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QMetaProperty
name|prop
init|=
name|meta
operator|->
name|property
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|prop
operator|.
name|isReadable
argument_list|()
condition|)
block|{
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|PropertyField
modifier|*
name|field
init|=
operator|new
name|PropertyField
argument_list|(
name|m_subject
argument_list|,
name|prop
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|m_formLayout
operator|->
name|addRow
argument_list|(
name|label
argument_list|,
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|,
literal|"name"
argument_list|)
condition|)
name|window
argument_list|()
operator|->
name|setWindowIconText
argument_list|(
name|prop
operator|.
name|read
argument_list|(
name|m_subject
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|label
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|field
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
name|connect
argument_list|(
name|m_subject
argument_list|,
operator|&
name|QObject
operator|::
name|destroyed
argument_list|,
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|subjectDestroyed
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|updateButton
init|=
operator|new
name|QPushButton
argument_list|(
name|QLatin1String
argument_list|(
literal|"Update"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|updateButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|updateAllFields
argument_list|)
expr_stmt|;
name|m_formLayout
operator|->
name|addRow
argument_list|(
name|QString
argument_list|()
argument_list|,
name|updateButton
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateAllFields
name|void
name|PropertyWatcher
operator|::
name|updateAllFields
parameter_list|()
block|{
name|QList
argument_list|<
name|PropertyField
modifier|*
argument_list|>
name|fields
init|=
name|findChildren
argument_list|<
name|PropertyField
operator|*
argument_list|>
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|PropertyField
modifier|*
name|field
decl|,
name|fields
control|)
name|field
operator|->
name|propertyChanged
argument_list|()
expr_stmt|;
emit|emit
name|updatedAllFields
argument_list|(
name|this
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|subjectDestroyed
name|void
name|PropertyWatcher
operator|::
name|subjectDestroyed
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"screen destroyed"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
