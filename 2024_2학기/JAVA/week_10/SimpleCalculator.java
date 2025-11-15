import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator {
    private JTextField inputField;
    private JLabel resultLabel;

    public SimpleCalculator() {
        // 프레임 생성
        JFrame frame = new JFrame("Simple Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 600);
        frame.setLayout(new BorderLayout());

        // 입력 필드
        inputField = new JTextField();
        inputField.setEditable(false);
        inputField.setFont(new Font("Arial", Font.PLAIN, 30));
        frame.add(inputField, BorderLayout.NORTH);

        // 결과 라벨
        resultLabel = new JLabel("0", SwingConstants.RIGHT);
        resultLabel.setFont(new Font("Arial", Font.PLAIN, 30));
        frame.add(resultLabel, BorderLayout.CENTER);

        // 버튼 패널
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));

        // 버튼 배열
        String[] buttons = {
                // 버튼 생성
                "1", "2", "3", "+",
                "4", "5", "6", "-",
                "7", "8", "9", "*",
                "0", "C", "=", "/"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.setFont(new Font("Arial", Font.PLAIN, 20));
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        frame.add(buttonPanel, BorderLayout.SOUTH);

        // 프레임을 보이도록 설정
        frame.setVisible(true);
    }

    // 버튼 클릭 리스너 템플릿
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand(); // 이벤트를 발생시킨 컴포넌트의 이름을 식별

            if (command.equals("C")) { // 'C' 버튼 클릭 시
                inputField.setText(""); // 필드 비우기
                resultLabel.setText("0"); // "0"을 표시
            }

            else if (command.equals("=")) {  // '=' 버튼 클릭 시
                evaluateExpression(); // 수식 계산하여 결과 표시
            }

            else { // 그 외 버튼 클릭 시
                inputField.setText(inputField.getText() + command);
            }
        }
    }

    // "=" 버튼을 눌렀을때 호출하는 메서드
    private void evaluateExpression() {
        String expression = inputField.getText();
        try {
            double result = sequentialEvaluation(expression); // 수식을 계산하여 결과값을 반환
            if (result == (long) result) { // 반환된 결과가 정수일 때
                resultLabel.setText(String.valueOf((long)result)); // 정수로만 표시
            }
            else { // 결과가 실수일 때
                resultLabel.setText(String.valueOf(result)); // 반환된 결과를 문자열로 표시
            }
        } catch (Exception e) {
            resultLabel.setText("Error");
        }
    }

    // 연산자를 고려하지 않고 왼쪽부터 순차적으로 계산하는 메소드
    private double sequentialEvaluation(String expression) throws Exception {
        String[] tokens = expression.split("(?<=[-+*/])|(?=[-+*/])"); // 정규 표현식으로 문자열을 Split하여 하나 하나 나눔
        double result = Double.parseDouble(tokens[0].trim());

        for (int i = 1; i < tokens.length; i += 2) {
            String operator = tokens[i];
            double nextValue = Double.parseDouble(tokens[i + 1].trim());

            switch (operator) {
                case "+": // 덧셈 연산
                    result += nextValue;
                    break;
                case "-": // 뺄셈 연산
                    result -= nextValue;
                    break;
                case "*": // 곱셈 연산
                    result *= nextValue;
                    break;
                case "/": // 나눗셈 연산
                    if (nextValue == 0) { // 0이 들어왔을 때
                        throw new ArithmeticException("나눗셈을 할 수 없습니다.");
                    }
                    result /= nextValue;
                    break;
                default: // 잘못된 연산자
                    throw new Exception("잘못 입력된 연산자 입니다.");
            }
        }
        return result;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SimpleCalculator()); // Swing 라이브러리에서 GUI 애플리케이션을 실행
    }
}
