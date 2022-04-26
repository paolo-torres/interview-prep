clc;
clear;

populationSize = 50;

numGenerations = 150;

crossoverProbability = 0.6;
mutationProbability = 0.25;

minKp = 2;
maxKp = 18;
deltaKp = 1;

minTi = 1.05;
maxTi = 9.42;
deltaTi = 0.1;

minTd = 0.26;
maxTd = 2.37;
deltaTd = 0.01;

Kp = minKp + (maxKp - minKp) * rand(populationSize, 1);
Ti = minTi + (maxTi - minTi) * rand(populationSize, 1);
Td = minTd + (maxTd - minTd) * rand(populationSize, 1);

inputs = zeros(populationSize, 3);
outputs = zeros(populationSize, 4);

inputsMin = zeros(1, 3);
fitnessMin = intmax;
outputMin = zeros(1, 4);

bestFitnesses = zeros(1, numGenerations);

for i = 1 : populationSize
    inputs(i, 1) = Kp(i);
    inputs(i, 2) = Ti(i);
    inputs(i, 3) = Td(i);
end

tic;

n = 1;
while n <= numGenerations
    fitnesses = zeros(populationSize, 1);
    fitnessSum = 0;

    for i = 1 : populationSize
        [outputs(i, 1), outputs(i, 2), outputs(i, 3), outputs(i, 4)] ... 
            = perfFCN(inputs(i, :));

        if outputs(i, 1) > 1000
            outputs(i, 1) = 0;
            outputs(i, 2) = 0;
            outputs(i, 3) = 0;
            outputs(i, 4) = 0;
        end

        fitnesses(i) = outputs(i, 1) + outputs(i, 2) + outputs(i, 3) ... 
            + outputs(i, 4);

        if fitnesses(i) > 0 && fitnesses(i) < fitnessMin
            inputsMin = [inputs(i, 1) inputs(i, 2) inputs(i, 3)];
            fitnessMin = fitnesses(i);
            outputMin = [outputs(i, 1) outputs(i, 2) outputs(i, 3) ... 
                outputs(i, 4)];
        end

        fitnessSum = fitnessSum + fitnesses(i);
    end
    
    bestFitnesses(n) = fitnessMin;

    fitnessAverage = fitnessSum / populationSize;

    probabilities = zeros(populationSize, 1);
    expectedCounts = zeros(populationSize, 1);

    for i = 1 : populationSize
        probabilities(i) = fitnesses(i) / fitnessSum;
        expectedCounts(i) = fitnesses(i) / fitnessAverage;
    end

    actualCounts = round(expectedCounts);

    for i = 1 : populationSize
        inputs(actualCounts(i) == 0, :) = [];
        outputs(actualCounts(i) == 0, :) = [];
    end

    actualCounts = actualCounts(actualCounts ~= 0);

    parentsToAdd = find(all(actualCounts == 2, 2));

    inputsToAdd = inputs(parentsToAdd, :);
    inputs = [inputs;inputsToAdd];

    outputsToAdd = outputs(parentsToAdd, :);
    outputs = [outputs;outputsToAdd];

    parentsToDelete = find(all(outputs == 0, 2));

    inputs(parentsToDelete, :) = [];
    outputs = outputs(any(outputs, 2), :);

    populationSize = size(outputs, 1);
    
    lesserOutputs = outputs;
    greaterOutputs = outputs;

    for i = 1 : populationSize
        applyOperator = rand;
        if applyOperator < crossoverProbability
            
            lesserKp = inputs(i, 1) - deltaKp;
            greaterKp = inputs(i, 1) + deltaKp;
            
            if lesserKp < minKp
                lesserKp = minKp;
            end
            
            if greaterKp > maxKp
                greaterKp = maxKp;
            end

            [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                = perfFCN([lesserKp inputs(i, 2) inputs(i, 3)]);

            [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                = perfFCN([greaterKp inputs(i, 2) inputs(i, 3)]);
            
            lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                + lesserOutputs(i, 3) + lesserOutputs(i, 4);

            greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                + greaterOutputs(i, 3) + greaterOutputs(i, 4);
            
            if lesserFitness < greaterFitness
                inputs(i, 1) = lesserKp;
            else
                inputs(i, 1) = greaterKp;
            end

            lesserTi = inputs(i, 2) - deltaTi;
            greaterTi = inputs(i, 2) + deltaTi;
            
            if lesserTi < minTi
                lesserTi = minTi;
            end
            
            if greaterTi > maxTi
                greaterTi = maxTi;
            end

            [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                = perfFCN([inputs(i, 1) lesserTi inputs(i, 3)]);

            [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                = perfFCN([inputs(i, 1) greaterTi inputs(i, 3)]);
            
            lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                + lesserOutputs(i, 3) + lesserOutputs(i, 4);

            greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                + greaterOutputs(i, 3) + greaterOutputs(i, 4);
            
            if lesserFitness < greaterFitness
                inputs(i, 2) = lesserTi;
            else
                inputs(i, 2) = greaterTi;
            end

            lesserTd = inputs(i, 3) - deltaTd;
            greaterTd = inputs(i, 3) + deltaTd;
            
            if lesserTd < minTd
                lesserTd = minTd;
            end
            
            if greaterTd > maxTd
                greaterTd = maxTd;
            end

            [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                = perfFCN([inputs(i, 1) inputs(i, 2) lesserTd]);

            [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                = perfFCN([inputs(i, 1) inputs(i, 2) greaterTd]);
            
            lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                + lesserOutputs(i, 3) + lesserOutputs(i, 4);

            greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                + greaterOutputs(i, 3) + greaterOutputs(i, 4);
            
            if lesserFitness < greaterFitness
                inputs(i, 3) = lesserTd;
            else
                inputs(i, 3) = greaterTd;
            end
        end

        applyOperator = rand;
        if applyOperator < mutationProbability
            mutationParameter = rand;

            if mutationParameter >= 0 && mutationParameter < 1/3
                lesserKp = inputs(i, 1) - deltaKp;
                greaterKp = inputs(i, 1) + deltaKp;

                if lesserKp < minKp
                    lesserKp = minKp;
                end

                if greaterKp > maxKp
                    greaterKp = maxKp;
                end

                [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                    lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                    = perfFCN([lesserKp inputs(i, 2) inputs(i, 3)]);

                [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                    greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                    = perfFCN([greaterKp inputs(i, 2) inputs(i, 3)]);

                lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                    + lesserOutputs(i, 3) + lesserOutputs(i, 4);

                greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                    + greaterOutputs(i, 3) + greaterOutputs(i, 4);

                if lesserFitness < greaterFitness
                    inputs(i, 1) = lesserKp;
                else
                    inputs(i, 1) = greaterKp;
                end

            elseif mutationParameter >= 1/3 && mutationParameter < 2/3
                lesserTi = inputs(i, 2) - deltaTi;
                greaterTi = inputs(i, 2) + deltaTi;

                if lesserTi < minTi
                    lesserTi = minTi;
                end

                if greaterTi > maxTi
                    greaterTi = maxTi;
                end

                [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                    lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                    = perfFCN([inputs(i, 1) lesserTi inputs(i, 3)]);

                [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                    greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                    = perfFCN([inputs(i, 1) greaterTi inputs(i, 3)]);

                lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                    + lesserOutputs(i, 3) + lesserOutputs(i, 4);

                greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                    + greaterOutputs(i, 3) + greaterOutputs(i, 4);

                if lesserFitness < greaterFitness
                    inputs(i, 2) = lesserTi;
                else
                    inputs(i, 2) = greaterTi;
                end

            else
                lesserTd = inputs(i, 3) - deltaTd;
                greaterTd = inputs(i, 3) + deltaTd;

                if lesserTd < minTd
                    lesserTd = minTd;
                end

                if greaterTd > maxTd
                    greaterTd = maxTd;
                end

                [lesserOutputs(i, 1), lesserOutputs(i, 2), ... 
                    lesserOutputs(i, 3), lesserOutputs(i, 4)] ... 
                    = perfFCN([inputs(i, 1) inputs(i, 2) lesserTd]);

                [greaterOutputs(i, 1), greaterOutputs(i, 2), ... 
                    greaterOutputs(i, 3), greaterOutputs(i, 4)] ... 
                    = perfFCN([inputs(i, 1) inputs(i, 2) greaterTd]);

                lesserFitness = lesserOutputs(i, 1) + lesserOutputs(i, 2) ... 
                    + lesserOutputs(i, 3) + lesserOutputs(i, 4);

                greaterFitness = greaterOutputs(i, 1) + greaterOutputs(i, 2) ... 
                    + greaterOutputs(i, 3) + greaterOutputs(i, 4);

                if lesserFitness < greaterFitness
                    inputs(i, 3) = lesserTd;
                else
                    inputs(i, 3) = greaterTd;
                end
            end
        end
    end
    
    n = n + 1;
    
    toc;
end

% generations = 1 : 1 : numGenerations;
% 
% plot(generations, bestFitnesses, 'LineWidth', 3);
% title('Fitness of Best Solution in Each Generation');
% xlabel('Generation');
% ylabel('Fitness of Best Solution');
% grid on;
% ax = gca;
% ax.FontSize = 24;
