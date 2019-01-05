USE MilitaryUnit

--вывести людей из офицерского состава

SELECT	[Soldiers].[ID] 
	,[Soldiers].[Name]
	,[Soldiers].[Surname]
	,[Rank].[NameOfRank]
	,[Soldiers].[RankID]
FROM [Soldiers], [Rank]
WHERE [Soldiers].[RankID] > 8 AND [Soldiers].[RankID] < 13
	AND [Soldiers].[RankID] = [Rank].[ID]