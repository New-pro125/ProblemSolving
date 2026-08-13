-- Write your PostgreSQL query statement below
SELECT *, CASE WHEN dna_sequence ~ '^ATG' THEN 1 ELSE 0 END as has_start, 
CASE WHEN dna_sequence ~ '(TAA|TAG|TGA)$' then 1 else 0 end as has_stop,
CASE WHEN dna_sequence ~ 'ATAT' then 1 else 0 end as has_atat,
CASE WHEN dna_sequence ~ 'GGG' then 1 else 0 end as has_ggg
FROM Samples
order by sample_id asc