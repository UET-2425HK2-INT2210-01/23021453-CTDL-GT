#ifdef bai1
Biểu thức chính quy / <[^ > ] + > / sẽ khớp với chuỗi :
1. < an xml tag >
3. < / closetag >
5. < with attribute = ”77” >
#endif bai1







#ifdef bai2
Biểu thức chính quy / a.[bc] + / sẽ khớp với chuỗi :
1.abc
2.abbbbbbbb
3.azc
4.abcbcbcbc
6.azccbbbbcbccc
#endif bai2








#ifdef bai3
Giải thích biểu thức :
(very)+→ phải có ít nhất một từ "very " đứng trước.
(fat) ? → có thể có hoặc không từ "fat " sau "very".
(tall | ugly) → bắt buộc phải có "tall" hoặc "ugly".
" man" → phải kếtthúc bằng " man".

Biểu thức chính quy / (very)+(fat) ? (tall | ugly) man / khớp với :
3. very very fat ugly man
4. very very very tall man
#endif bai3





#ifdef bai4
Biểu thức chính quy khớp đúng và chỉ đúng chuỗi có dạng "abc.def.ghi.jkx:
^ .{3}\..{3}\..{3}\..{3}$
#endif bai4





#ifdef bai5
Biểu thức khớp các số điện thoại ở các định dạng :
^ (\(\d{ 3 }\) | \d{ 3 })[\s. - ] ? \d{ 3 }[\s. - ] ? \d{ 4 }$
#endif bai5






#ifdef bai6
Biểu thức regular expression thỏa mãn tất cả các điều kiện :
^ [a - zA - Z0 - 9] + ([_ - ][a - zA - Z0 - 9] + ) * $
#endif bai6