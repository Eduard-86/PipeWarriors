// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystem/QuestNode.h"

FText UQuestNode::FormatQuestDescription()
{
	if (bHideProgress)
	{
		return Description;
	}
	else
	{
		return FText::Format(NSLOCTEXT("QuestSystem", "QuestRowInPanel", "{0}  ( {1} / {2} )"),
			Description,
			FText::AsNumber(currentProgress),
			FText::AsNumber(successProgress));
	}
}
