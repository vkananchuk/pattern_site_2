---
layout: default
title: bug2
pattern : p1
---

Codec-7
{% highlight java %}
 - return StringUtils.newStringUtf8(encodeBase64(binaryData, true));

 + return StringUtils.newStringUtf8(encodeBase64(binaryData, false));
{% endhighlight %}

Bug: [7](https://github.com/apache/commons-codec/compare/f7966c1b374ebdd3fccb28370d9cb80a2115d807...954d995c5603b616c3c4a9ffb1823f36dd7ebcb0), Project: [Codec](https://github.com/apache/commons-codec)
