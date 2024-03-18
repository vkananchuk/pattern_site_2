---
# Feel free to add content and custom Front Matter to this file.
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

---

## Description

[List of bug/fixes patterns](bug-fixes-patterns/bug-fixes-patterns.md)

| Identifier   | Project name         | Number of bugs / LHBs | Language |
|--------------|----------------------|-----------------------|----------|
| Chart        | jfreechart           | 26/                   | Java     |
| Cli          | commons-cli          | 39/                   | Java     |
| Closure      | closure-compiler     | 174/                  | Java     |
| Codec        | commons-codec        | 18/                   | Java     |
| Collections  | commons-collections5 | 4/                    | Java     |
| Compress     | commons-compress     | 47/                   | Java     |
| Csv          | commons-csv          | 16/                   | Java     |
| Gson         | gson                 | 18/                   | Java     |
| Lang         | commons-lang         | 64/                   | Java     |
| JacksonCore  | jackson-core         | 26/                   | Java     |
| JxPath       | commons-jxpath       | 22/                   | Java     |
| Mockito      | mockito              | 38/                   | Java     |

The projects listed in the table above are all sourced from [defects4j](https://github.com/rjust/defects4j)
## Categories of LHBs

1. [Missing null checking](#1-missing-null-checking)
2. [Incorrect variables](#2-incorrect-variables)
3. [Bugs related to -+1](#3-bugs-related-to--1)
4. [Misuse of order operators (<, ≤, ≥, > etc.)](#4-misuse-of-order-operators)
5. [False/True](#5-falsetrue)

## Detailed Descriptions

### 1. Missing Null Checking

Bugs related to missed null checks and the consequences of accessing null objects in the result.

##### Pattern example:

{% highlight java %}
  Buggy: func(obj.someMember)
  Fixed: if(obj != null) { func(obj.someMember) }
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](missing-null-checking-patterns/missing-null-checking-patterns.md)

### 2. Incorrect variables

Bugs related to incorrect usage of variables due to typos or similar names.

##### Pattern example:

{% highlight java %}
.
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](incorrect-variables-patterns)

### 3. Bugs related to -+1

Bugs associated with the absence of necessary +1 or -1, or conversely, with excessive use of +1, -1. his leads to issues such as array out-of-bounds, problems with loops, various conditions, and so on.

##### Pattern example:

{% highlight java %}
 Buggy: func(listArg1, val, listArg2)
 Fixed: func(listArg1, val + 1, listArg2)
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](bugs-related-to-1-patterns)

### 4. Misuse of order operators
Bugs related to improper use of comparison operators in if conditions, leading to incorrect code logic.

##### Pattern example:

{% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 < arg2) {}
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](misuse-of-order-operators-patterns/misuse-of-order-operators-patterns.md)


### 5. False/True

Logical bugs involving the use of true instead of false and vice versa.

##### Pattern example:

{% highlight java %}
 Buggy: func(listArg1, True, listArg2)
 Fixed: func(listArg1, False, listArg2)

{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](false-true-patterns/false-true-patterns.md)