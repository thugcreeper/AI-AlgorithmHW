package ntou.cs.java2025;
public class ComplexNumberCalculator{

    public static Complex calculate(Complex[][] matrix) {

        Complex[] sumMatrix =  new Complex[matrix.length];

        if (matrix == null || matrix.length == 0){
            throw new IllegalArgumentException(
                "Input matrix cannot be null or empty"
            );
        }

        for (int i = 0; i < matrix.length; i++) {
            sumMatrix[i] = new Complex(0, 0);
            for (int j = 0; j < matrix[i].length; j++) {
                sumMatrix[i] = sumMatrix[i].add(matrix[i][j]);
            }
        }

        Complex answer = sumMatrix[0];

        for (int i = 1; i < sumMatrix.length ; i++) {
            answer = answer.multiply(sumMatrix[i]);
        }

        return answer;
    }


}
