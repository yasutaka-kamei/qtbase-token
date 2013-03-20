begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsimplex_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \internal   \class QSimplex    The QSimplex class is a Linear Programming problem solver based on the two-phase   simplex method.    It takes a set of QSimplexConstraints as its restrictive constraints and an   additional QSimplexConstraint as its objective function. Then methods to maximize   and minimize the problem solution are provided.    The two-phase simplex method is based on the following steps:   First phase:   1.a) Modify the original, complex, and possibly not feasible problem, into a new,        easy to solve problem.   1.b) Set as the objective of the new problem, a feasible solution for the original        complex problem.   1.c) Run simplex to optimize the modified problem and check whether a solution for        the original problem exists.    Second phase:   2.a) Go back to the original problem with the feasibl (but not optimal) solution        found in the first phase.   2.b) Set the original objective.   3.c) Run simplex to optimize the original problem towards its optimal solution. */
end_comment
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QSimplex
name|QSimplex
operator|::
name|QSimplex
parameter_list|()
member_init_list|:
name|objective
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rows
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|columns
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|firstArtificial
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|matrix
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_destructor
DECL|function|~QSimplex
name|QSimplex
operator|::
name|~
name|QSimplex
parameter_list|()
block|{
name|clearDataStructures
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|clearDataStructures
name|void
name|QSimplex
operator|::
name|clearDataStructures
parameter_list|()
block|{
if|if
condition|(
name|matrix
operator|==
literal|0
condition|)
return|return;
comment|// Matrix
name|rows
operator|=
literal|0
expr_stmt|;
name|columns
operator|=
literal|0
expr_stmt|;
name|firstArtificial
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|matrix
argument_list|)
expr_stmt|;
name|matrix
operator|=
literal|0
expr_stmt|;
comment|// Constraints
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|constraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
operator|delete
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|first
expr_stmt|;
operator|delete
name|constraints
index|[
name|i
index|]
operator|->
name|artificial
expr_stmt|;
operator|delete
name|constraints
index|[
name|i
index|]
expr_stmt|;
block|}
name|constraints
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Other
name|variables
operator|.
name|clear
argument_list|()
expr_stmt|;
name|objective
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal   Sets the new constraints in the simplex solver and returns whether the problem   is feasible.    This method sets the new constraints, normalizes them, creates the simplex matrix   and runs the first simplex phase. */
end_comment
begin_function
DECL|function|setConstraints
name|bool
name|QSimplex
operator|::
name|setConstraints
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QSimplexConstraint
modifier|*
argument_list|>
name|newConstraints
parameter_list|)
block|{
comment|////////////////////////////
comment|// Reset to initial state //
comment|////////////////////////////
name|clearDataStructures
argument_list|()
expr_stmt|;
if|if
condition|(
name|newConstraints
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// we are ok with no constraints
comment|// Make deep copy of constraints. We need this copy because we may change
comment|// them in the simplification method.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|newConstraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSimplexConstraint
modifier|*
name|c
init|=
operator|new
name|QSimplexConstraint
decl_stmt|;
name|c
operator|->
name|constant
operator|=
name|newConstraints
index|[
name|i
index|]
operator|->
name|constant
expr_stmt|;
name|c
operator|->
name|ratio
operator|=
name|newConstraints
index|[
name|i
index|]
operator|->
name|ratio
expr_stmt|;
name|c
operator|->
name|variables
operator|=
name|newConstraints
index|[
name|i
index|]
operator|->
name|variables
expr_stmt|;
name|constraints
operator|<<
name|c
expr_stmt|;
block|}
comment|// Remove constraints of type Var == K and replace them for their value.
if|if
condition|(
operator|!
name|simplifyConstraints
argument_list|(
operator|&
name|constraints
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QSimplex: No feasible solution!"
expr_stmt|;
name|clearDataStructures
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|///////////////////////////////////////
comment|// Prepare variables and constraints //
comment|///////////////////////////////////////
comment|// Set Variables direct mapping.
comment|// "variables" is a list that provides a stable, indexed list of all variables
comment|// used in this problem.
name|QSet
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|>
name|variablesSet
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
name|constraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|variablesSet
operator|+=
expr|\
name|QSet
argument_list|<
name|QSimplexVariable
operator|*
argument_list|>
operator|::
name|fromList
argument_list|(
name|constraints
index|[
name|i
index|]
operator|->
name|variables
operator|.
name|keys
argument_list|()
argument_list|)
expr_stmt|;
name|variables
operator|=
name|variablesSet
operator|.
name|toList
argument_list|()
expr_stmt|;
comment|// Set Variables reverse mapping
comment|// We also need to be able to find the index for a given variable, to do that
comment|// we store in each variable its index.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
comment|// The variable "0" goes at the column "1", etc...
name|variables
index|[
name|i
index|]
operator|->
name|index
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
comment|// Normalize Constraints
comment|// In this step, we prepare the constraints in two ways:
comment|// Firstly, we modify all constraints of type "LessOrEqual" or "MoreOrEqual"
comment|// by the adding slack or surplus variables and making them "Equal" constraints.
comment|// Secondly, we need every single constraint to have a direct, easy feasible
comment|// solution. Constraints that have slack variables are already easy to solve,
comment|// to all the others we add artificial variables.
comment|//
comment|// At the end we modify the constraints as follows:
comment|//  - LessOrEqual: SLACK variable is added.
comment|//  - Equal: ARTIFICIAL variable is added.
comment|//  - More or Equal: ARTIFICIAL and SURPLUS variables are added.
name|int
name|variableIndex
init|=
name|variables
operator|.
name|size
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|>
name|artificialList
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
name|constraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSimplexVariable
modifier|*
name|slack
decl_stmt|;
name|QSimplexVariable
modifier|*
name|surplus
decl_stmt|;
name|QSimplexVariable
modifier|*
name|artificial
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|first
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|constraints
index|[
name|i
index|]
operator|->
name|artificial
operator|==
literal|0
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|constraints
index|[
name|i
index|]
operator|->
name|ratio
condition|)
block|{
case|case
name|QSimplexConstraint
operator|::
name|LessOrEqual
case|:
name|slack
operator|=
operator|new
name|QSimplexVariable
expr_stmt|;
name|slack
operator|->
name|index
operator|=
operator|++
name|variableIndex
expr_stmt|;
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|first
operator|=
name|slack
expr_stmt|;
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|second
operator|=
literal|1.0
expr_stmt|;
break|break;
case|case
name|QSimplexConstraint
operator|::
name|MoreOrEqual
case|:
name|surplus
operator|=
operator|new
name|QSimplexVariable
expr_stmt|;
name|surplus
operator|->
name|index
operator|=
operator|++
name|variableIndex
expr_stmt|;
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|first
operator|=
name|surplus
expr_stmt|;
name|constraints
index|[
name|i
index|]
operator|->
name|helper
operator|.
name|second
operator|=
operator|-
literal|1.0
expr_stmt|;
comment|// fall through
case|case
name|QSimplexConstraint
operator|::
name|Equal
case|:
name|artificial
operator|=
operator|new
name|QSimplexVariable
expr_stmt|;
name|constraints
index|[
name|i
index|]
operator|->
name|artificial
operator|=
name|artificial
expr_stmt|;
name|artificialList
operator|+=
name|constraints
index|[
name|i
index|]
operator|->
name|artificial
expr_stmt|;
break|break;
block|}
block|}
comment|// All original, slack and surplus have already had its index set
comment|// at this point. We now set the index of the artificial variables
comment|// as to ensure they are at the end of the variable list and therefore
comment|// can be easily removed at the end of this method.
name|firstArtificial
operator|=
name|variableIndex
operator|+
literal|1
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
name|artificialList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|artificialList
index|[
name|i
index|]
operator|->
name|index
operator|=
operator|++
name|variableIndex
expr_stmt|;
name|artificialList
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|/////////////////////////////
comment|// Fill the Simplex matrix //
comment|/////////////////////////////
comment|// One for each variable plus the Basic and BFS columns (first and last)
name|columns
operator|=
name|variableIndex
operator|+
literal|2
expr_stmt|;
comment|// One for each constraint plus the objective function
name|rows
operator|=
name|constraints
operator|.
name|size
argument_list|()
operator|+
literal|1
expr_stmt|;
name|matrix
operator|=
operator|(
name|qreal
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|*
name|columns
operator|*
name|rows
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|matrix
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QSimplex: Unable to allocate memory!"
expr_stmt|;
return|return
literal|false
return|;
block|}
for|for
control|(
name|int
name|i
init|=
name|columns
operator|*
name|rows
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
name|matrix
index|[
name|i
index|]
operator|=
literal|0.0
expr_stmt|;
comment|// Fill Matrix
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
name|constraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QSimplexConstraint
modifier|*
name|c
init|=
name|constraints
index|[
name|i
operator|-
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|->
name|artificial
condition|)
block|{
comment|// Will use artificial basic variable
name|setValueAt
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
name|c
operator|->
name|artificial
operator|->
name|index
argument_list|)
expr_stmt|;
name|setValueAt
argument_list|(
name|i
argument_list|,
name|c
operator|->
name|artificial
operator|->
name|index
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|->
name|helper
operator|.
name|second
operator|!=
literal|0.0
condition|)
block|{
comment|// Surplus variable
name|setValueAt
argument_list|(
name|i
argument_list|,
name|c
operator|->
name|helper
operator|.
name|first
operator|->
name|index
argument_list|,
name|c
operator|->
name|helper
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Slack is used as the basic variable
name|Q_ASSERT
argument_list|(
name|c
operator|->
name|helper
operator|.
name|second
operator|==
literal|1.0
argument_list|)
expr_stmt|;
name|setValueAt
argument_list|(
name|i
argument_list|,
literal|0
argument_list|,
name|c
operator|->
name|helper
operator|.
name|first
operator|->
name|index
argument_list|)
expr_stmt|;
name|setValueAt
argument_list|(
name|i
argument_list|,
name|c
operator|->
name|helper
operator|.
name|first
operator|->
name|index
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
block|}
name|QHash
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|,
name|qreal
argument_list|>
operator|::
name|const_iterator
name|iter
decl_stmt|;
for|for
control|(
name|iter
operator|=
name|c
operator|->
name|variables
operator|.
name|constBegin
argument_list|()
init|;
name|iter
operator|!=
name|c
operator|->
name|variables
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|setValueAt
argument_list|(
name|i
argument_list|,
name|iter
operator|.
name|key
argument_list|()
operator|->
name|index
argument_list|,
name|iter
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|setValueAt
argument_list|(
name|i
argument_list|,
name|columns
operator|-
literal|1
argument_list|,
name|c
operator|->
name|constant
argument_list|)
expr_stmt|;
block|}
comment|// Set objective for the first-phase Simplex.
comment|// Z = -1 * sum_of_artificial_vars
for|for
control|(
name|int
name|j
init|=
name|firstArtificial
init|;
name|j
operator|<
name|columns
operator|-
literal|1
condition|;
operator|++
name|j
control|)
name|setValueAt
argument_list|(
literal|0
argument_list|,
name|j
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
comment|// Maximize our objective (artificial vars go to zero)
name|solveMaxHelper
argument_list|()
expr_stmt|;
comment|// If there is a solution where the sum of all artificial
comment|// variables is zero, then all of them can be removed and yet
comment|// we will have a feasible (but not optimal) solution for the
comment|// original problem.
comment|// Otherwise, we clean up our structures and report there is
comment|// no feasible solution.
if|if
condition|(
operator|(
name|valueAt
argument_list|(
literal|0
argument_list|,
name|columns
operator|-
literal|1
argument_list|)
operator|!=
literal|0.0
operator|)
operator|&&
operator|(
name|qAbs
argument_list|(
name|valueAt
argument_list|(
literal|0
argument_list|,
name|columns
operator|-
literal|1
argument_list|)
argument_list|)
operator|>
literal|0.00001
operator|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QSimplex: No feasible solution!"
expr_stmt|;
name|clearDataStructures
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Remove artificial variables. We already have a feasible
comment|// solution for the first problem, thus we don't need them
comment|// anymore.
name|clearColumns
argument_list|(
name|firstArtificial
argument_list|,
name|columns
operator|-
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!   \internal    Run simplex on the current matrix with the current objective.    This is the iterative method. The matrix lines are combined   as to modify the variable values towards the best solution possible.   The method returns when the matrix is in the optimal state. */
end_comment
begin_function
DECL|function|solveMaxHelper
name|void
name|QSimplex
operator|::
name|solveMaxHelper
parameter_list|()
block|{
name|reducedRowEchelon
argument_list|()
expr_stmt|;
while|while
condition|(
name|iterate
argument_list|()
condition|)
empty_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|setObjective
name|void
name|QSimplex
operator|::
name|setObjective
parameter_list|(
name|QSimplexConstraint
modifier|*
name|newObjective
parameter_list|)
block|{
name|objective
operator|=
name|newObjective
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|clearRow
name|void
name|QSimplex
operator|::
name|clearRow
parameter_list|(
name|int
name|rowIndex
parameter_list|)
block|{
name|qreal
modifier|*
name|item
init|=
name|matrix
operator|+
name|rowIndex
operator|*
name|columns
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
name|columns
condition|;
operator|++
name|i
control|)
name|item
index|[
name|i
index|]
operator|=
literal|0.0
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|clearColumns
name|void
name|QSimplex
operator|::
name|clearColumns
parameter_list|(
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|rows
condition|;
operator|++
name|i
control|)
block|{
name|qreal
modifier|*
name|row
init|=
name|matrix
operator|+
name|i
operator|*
name|columns
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
name|first
init|;
name|j
operator|<=
name|last
condition|;
operator|++
name|j
control|)
name|row
index|[
name|j
index|]
operator|=
literal|0.0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|dumpMatrix
name|void
name|QSimplex
operator|::
name|dumpMatrix
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"---- Simplex Matrix ----\n"
argument_list|)
expr_stmt|;
name|QString
name|str
argument_list|(
name|QLatin1String
argument_list|(
literal|"       "
argument_list|)
argument_list|)
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
name|columns
condition|;
operator|++
name|j
control|)
name|str
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<%1>"
argument_list|)
operator|.
name|arg
argument_list|(
name|j
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|str
argument_list|)
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
name|rows
condition|;
operator|++
name|i
control|)
block|{
name|str
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Row %1:"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|qreal
modifier|*
name|row
init|=
name|matrix
operator|+
name|i
operator|*
name|columns
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
name|columns
condition|;
operator|++
name|j
control|)
name|str
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|row
index|[
name|j
index|]
argument_list|,
literal|7
argument_list|,
literal|'f'
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|(
literal|"------------------------\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|combineRows
name|void
name|QSimplex
operator|::
name|combineRows
parameter_list|(
name|int
name|toIndex
parameter_list|,
name|int
name|fromIndex
parameter_list|,
name|qreal
name|factor
parameter_list|)
block|{
if|if
condition|(
operator|!
name|factor
condition|)
return|return;
name|qreal
modifier|*
name|from
init|=
name|matrix
operator|+
name|fromIndex
operator|*
name|columns
decl_stmt|;
name|qreal
modifier|*
name|to
init|=
name|matrix
operator|+
name|toIndex
operator|*
name|columns
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|1
init|;
name|j
operator|<
name|columns
condition|;
operator|++
name|j
control|)
block|{
name|qreal
name|value
init|=
name|from
index|[
name|j
index|]
decl_stmt|;
comment|// skip to[j] = to[j] + factor*0.0
if|if
condition|(
name|value
operator|==
literal|0.0
condition|)
continue|continue;
name|to
index|[
name|j
index|]
operator|+=
name|factor
operator|*
name|value
expr_stmt|;
comment|// ### Avoid Numerical errors
if|if
condition|(
name|qAbs
argument_list|(
name|to
index|[
name|j
index|]
argument_list|)
operator|<
literal|0.0000000001
condition|)
name|to
index|[
name|j
index|]
operator|=
literal|0.0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|findPivotColumn
name|int
name|QSimplex
operator|::
name|findPivotColumn
parameter_list|()
block|{
name|qreal
name|min
init|=
literal|0
decl_stmt|;
name|int
name|minIndex
init|=
operator|-
literal|1
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
name|columns
operator|-
literal|1
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|valueAt
argument_list|(
literal|0
argument_list|,
name|j
argument_list|)
operator|<
name|min
condition|)
block|{
name|min
operator|=
name|valueAt
argument_list|(
literal|0
argument_list|,
name|j
argument_list|)
expr_stmt|;
name|minIndex
operator|=
name|j
expr_stmt|;
block|}
block|}
return|return
name|minIndex
return|;
block|}
end_function
begin_comment
comment|/*!   \internal    For a given pivot column, find the pivot row. That is, the row with the   minimum associated "quotient" where:    - quotient is the division of the value in the last column by the value     in the pivot column.   - rows with value less or equal to zero are ignored   - if two rows have the same quotient, lines are chosen based on the     highest variable index (value in the first column)    The last condition avoids a bug where artificial variables would be   left behind for the second-phase simplex, and with 'good'   constraints would be removed before it, what would lead to incorrect   results. */
end_comment
begin_function
DECL|function|pivotRowForColumn
name|int
name|QSimplex
operator|::
name|pivotRowForColumn
parameter_list|(
name|int
name|column
parameter_list|)
block|{
name|qreal
name|min
init|=
name|qreal
argument_list|(
literal|999999999999.0
argument_list|)
decl_stmt|;
comment|// ###
name|int
name|minIndex
init|=
operator|-
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|rows
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|divisor
init|=
name|valueAt
argument_list|(
name|i
argument_list|,
name|column
argument_list|)
decl_stmt|;
if|if
condition|(
name|divisor
operator|<=
literal|0
condition|)
continue|continue;
name|qreal
name|quotient
init|=
name|valueAt
argument_list|(
name|i
argument_list|,
name|columns
operator|-
literal|1
argument_list|)
operator|/
name|divisor
decl_stmt|;
if|if
condition|(
name|quotient
operator|<
name|min
condition|)
block|{
name|min
operator|=
name|quotient
expr_stmt|;
name|minIndex
operator|=
name|i
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|quotient
operator|==
name|min
operator|)
operator|&&
operator|(
name|valueAt
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
operator|>
name|valueAt
argument_list|(
name|minIndex
argument_list|,
literal|0
argument_list|)
operator|)
condition|)
block|{
name|minIndex
operator|=
name|i
expr_stmt|;
block|}
block|}
return|return
name|minIndex
return|;
block|}
end_function
begin_comment
comment|/*!   \internal */
end_comment
begin_function
DECL|function|reducedRowEchelon
name|void
name|QSimplex
operator|::
name|reducedRowEchelon
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|rows
condition|;
operator|++
name|i
control|)
block|{
name|int
name|factorInObjectiveRow
init|=
name|valueAt
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|combineRows
argument_list|(
literal|0
argument_list|,
name|i
argument_list|,
operator|-
literal|1
operator|*
name|valueAt
argument_list|(
literal|0
argument_list|,
name|factorInObjectiveRow
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal    Does one iteration towards a better solution for the problem.   See 'solveMaxHelper'. */
end_comment
begin_function
DECL|function|iterate
name|bool
name|QSimplex
operator|::
name|iterate
parameter_list|()
block|{
comment|// Find Pivot column
name|int
name|pivotColumn
init|=
name|findPivotColumn
argument_list|()
decl_stmt|;
if|if
condition|(
name|pivotColumn
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
comment|// Find Pivot row for column
name|int
name|pivotRow
init|=
name|pivotRowForColumn
argument_list|(
name|pivotColumn
argument_list|)
decl_stmt|;
if|if
condition|(
name|pivotRow
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QSimplex: Unbounded problem!"
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Normalize Pivot Row
name|qreal
name|pivot
init|=
name|valueAt
argument_list|(
name|pivotRow
argument_list|,
name|pivotColumn
argument_list|)
decl_stmt|;
if|if
condition|(
name|pivot
operator|!=
literal|1.0
condition|)
name|combineRows
argument_list|(
name|pivotRow
argument_list|,
name|pivotRow
argument_list|,
operator|(
literal|1.0
operator|-
name|pivot
operator|)
operator|/
name|pivot
argument_list|)
expr_stmt|;
comment|// Update other rows
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
operator|++
name|row
control|)
block|{
if|if
condition|(
name|row
operator|==
name|pivotRow
condition|)
continue|continue;
name|combineRows
argument_list|(
name|row
argument_list|,
name|pivotRow
argument_list|,
operator|-
literal|1
operator|*
name|valueAt
argument_list|(
name|row
argument_list|,
name|pivotColumn
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Update first column
name|setValueAt
argument_list|(
name|pivotRow
argument_list|,
literal|0
argument_list|,
name|pivotColumn
argument_list|)
expr_stmt|;
comment|//    dumpMatrix();
comment|//    qDebug("------------ end of iteration --------------\n");
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!   \internal    Both solveMin and solveMax are interfaces to this method.    The enum solverFactor admits 2 values: Minimum (-1) and Maximum (+1).    This method sets the original objective and runs the second phase   Simplex to obtain the optimal solution for the problem. As the internal   simplex solver is only able to _maximize_ objectives, we handle the   minimization case by inverting the original objective and then   maximizing it. */
end_comment
begin_function
DECL|function|solver
name|qreal
name|QSimplex
operator|::
name|solver
parameter_list|(
name|solverFactor
name|factor
parameter_list|)
block|{
comment|// Remove old objective
name|clearRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// Set new objective in the first row of the simplex matrix
name|qreal
name|resultOffset
init|=
literal|0
decl_stmt|;
name|QHash
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|,
name|qreal
argument_list|>
operator|::
name|const_iterator
name|iter
decl_stmt|;
for|for
control|(
name|iter
operator|=
name|objective
operator|->
name|variables
operator|.
name|constBegin
argument_list|()
init|;
name|iter
operator|!=
name|objective
operator|->
name|variables
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
comment|// Check if the variable was removed in the simplification process.
comment|// If so, we save its offset to the objective function and skip adding
comment|// it to the matrix.
if|if
condition|(
name|iter
operator|.
name|key
argument_list|()
operator|->
name|index
operator|==
operator|-
literal|1
condition|)
block|{
name|resultOffset
operator|+=
name|iter
operator|.
name|value
argument_list|()
operator|*
name|iter
operator|.
name|key
argument_list|()
operator|->
name|result
expr_stmt|;
continue|continue;
block|}
name|setValueAt
argument_list|(
literal|0
argument_list|,
name|iter
operator|.
name|key
argument_list|()
operator|->
name|index
argument_list|,
operator|-
literal|1
operator|*
name|factor
operator|*
name|iter
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|solveMaxHelper
argument_list|()
expr_stmt|;
name|collectResults
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_DEBUG
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|constraints
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Q_ASSERT
argument_list|(
name|constraints
index|[
name|i
index|]
operator|->
name|isSatisfied
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Return the value calculated by the simplex plus the value of the
comment|// fixed variables.
return|return
operator|(
name|factor
operator|*
name|valueAt
argument_list|(
literal|0
argument_list|,
name|columns
operator|-
literal|1
argument_list|)
operator|)
operator|+
name|resultOffset
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   Minimize the original objective. */
end_comment
begin_function
DECL|function|solveMin
name|qreal
name|QSimplex
operator|::
name|solveMin
parameter_list|()
block|{
return|return
name|solver
argument_list|(
name|Minimum
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   Maximize the original objective. */
end_comment
begin_function
DECL|function|solveMax
name|qreal
name|QSimplex
operator|::
name|solveMax
parameter_list|()
block|{
return|return
name|solver
argument_list|(
name|Maximum
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal    Reads results from the simplified matrix and saves them in the   "result" member of each QSimplexVariable. */
end_comment
begin_function
DECL|function|collectResults
name|void
name|QSimplex
operator|::
name|collectResults
parameter_list|()
block|{
comment|// All variables are zero unless overridden below.
comment|// ### Is this really needed? Is there any chance that an
comment|// important variable remains as non-basic at the end of simplex?
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|variables
index|[
name|i
index|]
operator|->
name|result
operator|=
literal|0
expr_stmt|;
comment|// Basic variables
comment|// Update the variable indicated in the first column with the value
comment|// in the last column.
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|rows
condition|;
operator|++
name|i
control|)
block|{
name|int
name|index
init|=
name|valueAt
argument_list|(
name|i
argument_list|,
literal|0
argument_list|)
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|index
operator|<
name|variables
operator|.
name|size
argument_list|()
condition|)
name|variables
index|[
name|index
index|]
operator|->
name|result
operator|=
name|valueAt
argument_list|(
name|i
argument_list|,
name|columns
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   \internal    Looks for single-valued variables and remove them from the constraints list. */
end_comment
begin_function
DECL|function|simplifyConstraints
name|bool
name|QSimplex
operator|::
name|simplifyConstraints
parameter_list|(
name|QList
argument_list|<
name|QSimplexConstraint
modifier|*
argument_list|>
modifier|*
name|constraints
parameter_list|)
block|{
name|QHash
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|,
name|qreal
argument_list|>
name|results
decl_stmt|;
comment|// List of single-valued variables
name|bool
name|modified
init|=
literal|true
decl_stmt|;
comment|// Any chance more optimization exists?
while|while
condition|(
name|modified
condition|)
block|{
name|modified
operator|=
literal|false
expr_stmt|;
comment|// For all constraints
name|QList
argument_list|<
name|QSimplexConstraint
modifier|*
argument_list|>
operator|::
name|iterator
name|iter
init|=
name|constraints
operator|->
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|iter
operator|!=
name|constraints
operator|->
name|end
argument_list|()
condition|)
block|{
name|QSimplexConstraint
modifier|*
name|c
init|=
operator|*
name|iter
decl_stmt|;
if|if
condition|(
operator|(
name|c
operator|->
name|ratio
operator|==
name|QSimplexConstraint
operator|::
name|Equal
operator|)
operator|&&
operator|(
name|c
operator|->
name|variables
operator|.
name|count
argument_list|()
operator|==
literal|1
operator|)
condition|)
block|{
comment|// Check whether this is a constraint of type Var == K
comment|// If so, save its value to "results".
name|QSimplexVariable
modifier|*
name|variable
init|=
name|c
operator|->
name|variables
operator|.
name|constBegin
argument_list|()
operator|.
name|key
argument_list|()
decl_stmt|;
name|qreal
name|result
init|=
name|c
operator|->
name|constant
operator|/
name|c
operator|->
name|variables
operator|.
name|value
argument_list|(
name|variable
argument_list|)
decl_stmt|;
name|results
operator|.
name|insert
argument_list|(
name|variable
argument_list|,
name|result
argument_list|)
expr_stmt|;
name|variable
operator|->
name|result
operator|=
name|result
expr_stmt|;
name|variable
operator|->
name|index
operator|=
operator|-
literal|1
expr_stmt|;
name|modified
operator|=
literal|true
expr_stmt|;
block|}
comment|// Replace known values among their variables
name|QHash
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|,
name|qreal
argument_list|>
operator|::
name|const_iterator
name|r
decl_stmt|;
for|for
control|(
name|r
operator|=
name|results
operator|.
name|constBegin
argument_list|()
init|;
name|r
operator|!=
name|results
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|r
control|)
block|{
if|if
condition|(
name|c
operator|->
name|variables
operator|.
name|contains
argument_list|(
name|r
operator|.
name|key
argument_list|()
argument_list|)
condition|)
block|{
name|c
operator|->
name|constant
operator|-=
name|r
operator|.
name|value
argument_list|()
operator|*
name|c
operator|->
name|variables
operator|.
name|take
argument_list|(
name|r
operator|.
name|key
argument_list|()
argument_list|)
expr_stmt|;
name|modified
operator|=
literal|true
expr_stmt|;
block|}
block|}
comment|// Keep it normalized
if|if
condition|(
name|c
operator|->
name|constant
operator|<
literal|0
condition|)
name|c
operator|->
name|invert
argument_list|()
expr_stmt|;
if|if
condition|(
name|c
operator|->
name|variables
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// If constraint became empty due to substitution, delete it.
if|if
condition|(
name|c
operator|->
name|isSatisfied
argument_list|()
operator|==
literal|false
condition|)
comment|// We must ensure that the constraint soon to be deleted would not
comment|// make the problem unfeasible if left behind. If that's the case,
comment|// we return false so the simplex solver can properly report that.
return|return
literal|false
return|;
operator|delete
name|c
expr_stmt|;
name|iter
operator|=
name|constraints
operator|->
name|erase
argument_list|(
name|iter
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|iter
expr_stmt|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|invert
name|void
name|QSimplexConstraint
operator|::
name|invert
parameter_list|()
block|{
name|constant
operator|=
operator|-
name|constant
expr_stmt|;
name|ratio
operator|=
name|Ratio
argument_list|(
literal|2
operator|-
name|ratio
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|QSimplexVariable
modifier|*
argument_list|,
name|qreal
argument_list|>
operator|::
name|iterator
name|iter
decl_stmt|;
for|for
control|(
name|iter
operator|=
name|variables
operator|.
name|begin
argument_list|()
init|;
name|iter
operator|!=
name|variables
operator|.
name|end
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|iter
operator|.
name|value
argument_list|()
operator|=
operator|-
name|iter
operator|.
name|value
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
