WITH words AS (
  SELECT content_id, content_text, pos, word
  FROM user_content,
       LATERAL unnest(string_to_array(content_text, ' ')) WITH ORDINALITY AS t(word, pos)
), fixed AS (
  SELECT content_id, content_text, pos,
    CASE
      WHEN word ~ '^[A-Za-z]+-[A-Za-z]+$'
      THEN initcap(split_part(word,'-',1)) || '-' || initcap(split_part(word,'-',2))
      ELSE upper(left(word,1)) || lower(substring(word from 2))
    END AS word
  FROM words
)
SELECT content_id, content_text AS original_text,
       string_agg(word, ' ' ORDER BY pos) AS converted_text
FROM fixed
GROUP BY content_id, content_text
ORDER BY content_id;