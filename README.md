# gitacp
Actually gitacp does this:
```c
git add --all && git add . && git commit -am '  * your comment goes here' && git push
```
and outputs something like this:
```
--[master af65f23] 	*	#no-issue. error exit + color fixes
--
-- 1 file changed, 3 insertions(+), 2 deletions(-)
--
```
pretty colored.

### Installation
Download gitacp.zip unzip, then:

```
cd gitacp/
cp gitacp /usr/local/bin/gitacp
```

That's it.
